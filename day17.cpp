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
typedef long long LL;
const int N=150;

vector<string> g;
int d[N][N][4][14];
bool st[N][N][4][14];
array<int,4> fa[N][N][4][14];
int n,m;
int dx[4]={1,0,-1,0};
int dy[4]={0,-1,0,1};

void bfs(){
	priority_queue<array<int,5>,vector<array<int,5>>,greater<array<int,5>>> q;
	q.push({0,0,0,3,1});
	q.push({0,0,0,0,1});
	d[0][0][3][1]=d[0][0][0][1]=0;
	while(q.size()){
		auto t=q.top();
		q.pop();
		int c=t[0],x=t[1],y=t[2],fx=t[3],cnt=t[4];
		if(st[x][y][fx][cnt]) continue;
		st[x][y][fx][cnt]=1;
		
		if(cnt<4){
			int i=fx;
			int nx=x+dx[i],ny=y+dy[i];
			if(nx<0 or nx>=n or ny<0 or ny>=m) continue;
			int w=g[nx][ny]-'0';
			auto &tt=d[nx][ny][i][i==fx ? cnt+1:1];
			if(tt==-1 or tt>c+w){
				tt=c+w;
				fa[nx][ny][i][i==fx ? cnt+1:1]={x,y,fx,cnt};
				q.push({c+w,nx,ny,i,i==fx ? cnt+1 : 1});
			}
		}else{
			for(int i=0;i<4;i++){
				if(cnt==10 and fx==i) continue;
				if((fx^i)==2) continue;
				int nx=x+dx[i],ny=y+dy[i];
				if(nx<0 or nx>=n or ny<0 or ny>=m) continue;
				int w=g[nx][ny]-'0';
				auto &tt=d[nx][ny][i][i==fx ? cnt+1:1];
				if(tt==-1 or tt>c+w){
					tt=c+w;
					fa[nx][ny][i][i==fx ? cnt+1:1]={x,y,fx,cnt};
					q.push({c+w,nx,ny,i,i==fx ? cnt+1 : 1});
				}
			}
		}
	}
}

void solve(){
	string s;
	while(cin>>s){
		g.pb(s);
	}
	n=g.size(),m=g[0].size();
	memset(d,-1,sizeof d);
	bfs();
	int xx=n-1,yy=m-1,fx=0,cnt=3;
	array<int,4> c={0,0,3,1};
	while(xx!=0 or yy!=0){
		auto tt=fa[xx][yy][fx][cnt];
		
		xx=tt[0],yy=tt[1],fx=tt[2],cnt=tt[3];
	}
	int res=1e18;
	for(int i=0;i<4;i++){
		for(int j=4;j<=10;j++) {
			if(d[n-1][m-1][i][j]==-1) continue;
			res=min(res,d[n-1][m-1][i][j]);
		}
	}
	cout<<res;
	
}

signed main(){
    fastio;
    
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}