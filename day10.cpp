/*
lengli_QAQ
Hope there are no bugs!!!
*/
#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define endl '\n'
#define all(x) x.begin(),x.end()
#define pb push_back

using namespace std;


using _T=double; //long long
 
constexpr _T eps=1e-8;
constexpr long double PI=3.1415926535897932384l;
 
template<typename T> struct point
{
    T x,y;
 
    bool operator==(const point &a) const {return (abs(x-a.x)<=eps && abs(y-a.y)<=eps);}
    bool operator<(const point &a) const {if (abs(x-a.x)<=eps) return y<a.y-eps; return x<a.x-eps;}
    bool operator>(const point &a) const {return !(*this<a || *this==a);}
    point operator+(const point &a) const {return {x+a.x,y+a.y};}
    point operator-(const point &a) const {return {x-a.x,y-a.y};}
    point operator-() const {return {-x,-y};}
    point operator*(const T k) const {return {k*x,k*y};}
    point operator/(const T k) const {return {x/k,y/k};}
    T operator*(const point &a) const {return x*a.x+y*a.y;}
    T operator^(const point &a) const {return x*a.y-y*a.x;}
    int toleft(const point &a) const {const auto t=(*this)^a; return (t>eps)-(t<-eps);}
    T len2() const {return (*this)*(*this);}
    T dis2(const point &a) const {return (a-(*this)).len2();}
    double len() const {return sqrt(len2());}
    double dis(const point &a) const {return sqrt(dis2(a));}
    double ang(const point &a) const {return acos(max(-1.0,min(1.0,((*this)*a)/(len()*a.len()))));}
    //point rot(const double rad) const {return {x*cos(rad)-y*sin(rad),x*sin(rad)+y*cos(rad)};}
    //point rot(const double cosr,const double sinr) const {return {x*cosr-y*sinr,x*sinr+y*cosr};}
};
 
using Point=point<_T>;
 
struct argcmp
{
    bool operator()(const Point &a,const Point &b) const
    {
        const auto quad=[](const Point &a)
        {
            if (a.y<-eps) return 1;
            if (a.y>eps) return 4;
            if (a.x<-eps) return 5;
            if (a.x>eps) return 3;
            return 2;
        };
        const int qa=quad(a),qb=quad(b);
        if (qa!=qb) return qa<qb;
        const auto t=a^b;
        //if (abs(t)<=eps) return a*a<b*b-eps;
        return t>eps;
    }
};
 
template<typename T> struct line
{
    point<T> p,v;
 
    bool operator==(const line &a) const {return v.toleft(a.v)==0 && v.toleft(p-a.p)==0;}
    int toleft(const point<T> &a) const {return v.toleft(a-p);}
    point<T> inter(const line &a) const {return p+v*((a.v^(p-a.p))/(v^a.v));}
    double dis(const point<T> &a) const {return abs(v^(a-p))/v.len();}
    point<T> proj(const point<T> &a) const {return p+v*((v*(a-p))/(v*v));}
    bool operator<(const line &a) const
    {
        if (abs(v^a.v)<=eps && v*a.v>=-eps) return toleft(a.p)==-1;
        return argcmp()(v,a.v);
    }
};
 
using Line=line<_T>;
 
template<typename T> struct segment
{
    point<T> a,b;
 
    int is_on(const point<T> &p) const
    {
        if (p==a || p==b) return -1;
        return (p-a).toleft(p-b)==0 && (p-a)*(p-b)<-eps;
    }
 
    int is_inter(const line<T> &l) const
    {
        if (l.toleft(a)==0 || l.toleft(b)==0) return -1;
        return l.toleft(a)!=l.toleft(b);
    }
     
    int is_inter(const segment<T> &s) const
    {
        if (is_on(s.a) || is_on(s.b) || s.is_on(a) || s.is_on(b)) return -1;
        const line<T> l{a,b-a},ls{s.a,s.b-s.a};
        return l.toleft(s.a)*l.toleft(s.b)==-1 && ls.toleft(a)*ls.toleft(b)==-1;
    }
 
    double dis(const point<T> &p) const
    {
        if ((p-a)*(b-a)<-eps || (p-b)*(a-b)<-eps) return min(p.dis(a),p.dis(b));
        const line<T> l{a,b-a};
        return l.dis(p);
    }
 
    double dis(const segment<T> &s) const
    {
        if (is_inter(s)) return 0;
        return min({dis(s.a),dis(s.b),s.dis(a),s.dis(b)});
    }
};
 
using Segment=segment<_T>;
 
template<typename T> struct polygon
{
    vector<point<T>> p;
 
    size_t nxt(const size_t i) const {return i==p.size()-1?0:i+1;}
    size_t pre(const size_t i) const {return i==0?p.size()-1:i-1;}
 
    pair<bool,int> winding(const point<T> &a) const
    {
        int cnt=0;
        for (size_t i=0;i<p.size();i++)
        {
            point<T> u=p[i],v=p[nxt(i)];
            if (abs((a-u)^(a-v))<=eps && (a-u)*(a-v)<=eps) return {true,0};
            if (abs(u.y-v.y)<=eps) continue;
            const Line uv={u,v-u};
            if (u.y<v.y-eps && uv.toleft(a)<=0) continue;
            if (u.y>v.y+eps && uv.toleft(a)>=0) continue;
            if (u.y<a.y-eps && v.y>=a.y-eps) cnt++;
            if (u.y>=a.y-eps && v.y<a.y-eps) cnt--;
        }
        return {false,cnt};
    }
 
    double circ() const
    {
        double sum=0;
        for (size_t i=0;i<p.size();i++) sum+=p[i].dis(p[nxt(i)]);
        return sum;
    }
 
    T area() const
    {
        T sum=0;
        for (size_t i=0;i<p.size();i++) sum+=p[i]^p[nxt(i)];
        return sum;
    }
};
 
using Polygon=polygon<_T>;

class Solution {
public:
    vector<bool> isPointInPolygon(vector<pair<double,double>> aa, vector<double>& coords) {
        int n = coords.size();
        Polygon p;
        for (int i = 0; i < n; i += 2) {
            p.p.push_back({coords[i], coords[i + 1]});
        }
        reverse(p.p.begin(), p.p.end());
        vector<bool> res;
        for(auto t:aa){
        	auto [a, b] = p.winding({t.first, t.second});
        	res.pb(a or b);
        }
        
        return res;
    }
};

//--------------------------------
template<typename T> void printvt(vector<T> &a){
	for(auto x:a) cout<<x<<" ";cout<<endl;
};
template<typename T> void printay(T a[],int l,int r){
	for(int i=l;i<=r;i++) cout<<a[i]<<" ";cout<<endl;
};
//--------------------------------

typedef pair<int,int> PII;
typedef long long LL;
const int N=100010;

int n,m;
vector<string> g;
vector<string> q;
int dx[4]={-1,0,1,0};
int dy[4]={0,1,0,-1};
vector<double> a,b;

int sx,sy;

array<int,3> get(int come,int x,int y,int len,vector<double> b){
	if(x<0 or x>=n or y<0 or y>=m) return {-1,-1,-1};
	if(g[x][y]=='.') return {-1,-1,-1};
	if(x==sx and y==sy) {
		a=b;
		return {-2,-2,len};
	}
	b.pb(x),b.pb(y);
	q[x][y]='B';
	if(come==0){
		if(g[x][y]=='|') return get(0,x+dx[0],y+dy[0],len+1,b);
		if(g[x][y]=='-') return {-1,-1,-1};
		if(g[x][y]=='L') return {-1,-1,-1};
		if(g[x][y]=='J') return {-1,-1,-1};
		if(g[x][y]=='7') return get(3,x+dx[3],y+dy[3],len+1,b);
		if(g[x][y]=='F') return get(1,x+dx[1],y+dy[1],len+1,b);
	}else if(come==1){
		if(g[x][y]=='|') return {-1,-1,-1};
		if(g[x][y]=='-') return get(1,x+dx[1],y+dy[1],len+1,b);
		if(g[x][y]=='L') return {-1,-1,-1};
		if(g[x][y]=='J') return get(0,x+dx[0],y+dy[0],len+1,b);
		if(g[x][y]=='7') return get(2,x+dx[2],y+dy[2],len+1,b);
		if(g[x][y]=='F') return {-1,-1,-1};
	}else if(come==2){
		if(g[x][y]=='|') return get(2,x+dx[2],y+dy[2],len+1,b);
		if(g[x][y]=='-') return {-1,-1,-1};
		if(g[x][y]=='L') return get(1,x+dx[1],y+dy[1],len+1,b);
		if(g[x][y]=='J') return get(3,x+dx[3],y+dy[3],len+1,b);
		if(g[x][y]=='7') return {-1,-1,-1};
		if(g[x][y]=='F') return {-1,-1,-1};
	}else{
		if(g[x][y]=='|') return {-1,-1,-1};
		if(g[x][y]=='-') return get(3,x+dx[3],y+dy[3],len+1,b);
		if(g[x][y]=='L') return get(0,x+dx[0],y+dy[0],len+1,b);
		if(g[x][y]=='J') return {-1,-1,-1};
		if(g[x][y]=='7') return {-1,-1,-1};
		if(g[x][y]=='F') return get(2,x+dx[2],y+dy[2],len+1,b);
	}
	
	return {-1,-1,-1};
}


void solve(){
	string s;
	while(cin>>s) g.pb(s);
	n=g.size(),m=g[0].size();
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++) {
			if(g[i][j]=='S') sx=i,sy=j;
		}
	int st=0;
	for(int i=0;i<4;i++){
		q=g;b.clear();
		auto t=get(i,sx+dx[i],sy+dy[i],1,b);
		if(t[0]!=-1){
			st=i;
			break;
		}
		
	}
	b.clear();
	q=g;q[sx][sy]='B';
	auto t=get(st,sx+dx[st],sy+dy[st],1,b);

	
	vector<pair<double,double>> bb;
	Solution res;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++) {
			if(q[i][j]!='B') {
				bb.pb({i,j});
			}
		}
	}
	auto ans=res.isPointInPolygon(bb,a);
	int r=0;
	for(auto x:ans) r+=x;
	cout<<r;
}

signed main(){
    fastio;
    
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}