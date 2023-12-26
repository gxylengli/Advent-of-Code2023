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
const int N=1010;

vector<string> g;
int n,m;
int sx,sy,ex,ey;

//u,r,d,l
int dx[4]={-1,0,1,0};
int dy[4]={0,1,0,-1};

int d[N][N];
int fx[N][N];
bool st[N][N];

void dfs(int x,int y,int len){
	d[x][y]=max(d[x][y],len);
	for(int i=0;i<4;i++){
		//part1
		//if(fx[x][y]!=-1 and fx[x][y]!=i) continue;
		int nx=x+dx[i],ny=y+dy[i];
		if(nx<0 or nx>=n or ny<0 or ny>=m or g[nx][ny]=='#' or st[nx][ny]) continue;
		st[nx][ny]=1;
		dfs(nx,ny,len+1);
		st[nx][ny]=0;
	}
}

void solve(){
	string s;
	while(cin>>s) g.pb(s);
	n=g.size(),m=g[0].size();
	memset(fx,-1,sizeof fx);
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++){
			char c=g[i][j];
			if(c=='^') fx[i][j]=0;
			else if(c=='>') fx[i][j]=1;
			else if(c=='v') fx[i][j]=2;
			else if(c=='<') fx[i][j]=3;
		}
	
	for(int j=0;j<m;j++) if(g[0][j]=='.') sx=0,sy=j;
	for(int j=0;j<m;j++) if(g[n-1][j]=='.') ex=n-1,ey=j;
	
	st[sx][sy]=1;
	dfs(sx,sy,0);
	cout<<d[ex][ey];
}

signed main(){
    fastio;
    
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}