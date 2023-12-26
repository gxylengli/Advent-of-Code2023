/*
lengli_QAQ
Hope there are no bugs!!!
*/
#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define endl '\n'
#define all(x) x.begin(),x.end()
#define pb push_back

#define int long long
#define LL __int128
using namespace std;

//--------------------------------
template<typename T> void printvt(vector<T> &a){
	for(auto x:a) cout<<x<<" ";cout<<endl;
};
template<typename T> void printay(T a[],int l,int r){
	for(int i=l;i<=r;i++) cout<<a[i]<<" ";cout<<endl;
};
//--------------------------------

typedef pair<int,int> PII;
const int N=100010;

struct Point {
  LL x, y;
  Point(LL x0 = 0, LL y0 = 0) : x(x0), y(y0) {}
  friend Point operator-(const Point &a, const Point &b) {
    return Point(a.x - b.x, a.y - b.y);
  }
};

LL Cross(const Point &a, const Point &b)  {
  return a.x * b.y - a.y * b.x;
}

LL PolygonArea(Point *p, int n)  {
  LL ret = 0;
  for (int i = 2; i < n; i++)  
    ret += Cross(p[i] - p[1], p[i + 1] - p[1]);
  return ret / 2;
}

int idx;
Point a[N];
int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0};

PII get(string s){
	s.erase(0,2);
	s.pop_back();
	int l=s.back()-'0';
	s.pop_back();
	int r=0,b=1;
	for(int i=s.size()-1;i>=0;i--,b*=16){
		char c=s[i];
		if(c>='0' and c<='9') r+=(c-'0')*b;
		else r+=((c-'a')+10)*b;
	}
	return {l,r};
}

void solve(){
	char c;
	int x;
	string s;
	LL sx=0,sy=0;
	a[++idx]={sx,sy};
	int sum=0;
	while(cin>>c>>x>>s){
		PII t=get(s);
		LL xx=dx[t.first],yy=dy[t.first];
		sx+=xx*t.second,sy+=yy*t.second;
		a[++idx]={sx,sy};
		sum+=t.second;
	}
	reverse(a+1,a+1+idx);
	cout<<(int)PolygonArea(a,idx)-sum/2+1+sum;
}

signed main(){
    fastio;
    
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}