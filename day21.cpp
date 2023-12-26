/*
lengli_QAQ
Hope there are no bugs!!!
*/
#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define endl '\n'
#define all(x) x.begin(),x.end()
#define pb emplace_back

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
const int N=210;

vector<string> g;
int n,m,sx,sy;

int dx[4]={1,0,-1,0};
int dy[4]={0,-1,0,1};

bool st[N][N][100];

set<PII> bfs(int tt){
	set<PII> res;
	vector<PII> ans;
	queue<array<int,3>> q;
	q.push({sx,sy,1});
	while(q.size()){
		auto t=q.front();
		q.pop();
		if(t[2]>tt) continue;
		if(t[2]==tt){
			ans.pb(t[0],t[1]);
			continue;
		}
		if(st[t[0]][t[1]][t[2]]) continue;
		st[t[0]][t[1]][t[2]]=1;
		for(int i=0;i<4;i++){
			int nx=t[0]+dx[i],ny=t[1]+dy[i];
			if(nx<0 or nx>=n or ny<0 or ny>=m or g[nx][ny]=='#') continue;
			q.push({nx,ny,t[2]+1});
		}
		
	}
	for(auto [x,y]:ans){
		for(int i=0;i<4;i++){
			int nx=x+dx[i],ny=y+dy[i];
			if(nx<0 or nx>=n or ny<0 or ny>=m or g[nx][ny]=='#') continue;
			res.insert({nx,ny});
		}
	}
	return res;
}

void solve(){
	string s;
	while(cin>>s) g.pb(s);
	n=g.size(),m=g[0].size();
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++){
			if(g[i][j]=='S') g[i][j]='.',sx=i,sy=j;
		}
	int tot=124;
	set<int> k={tot};
	for(int i=tot-1,j=1;j>=1;i--,j++){
		int r=i-j;
		if(r<1) break;
		k.insert(r);
	}
	cout<<k.size()<<endl;
	set<PII> res=bfs(64);
	cout<<res.size()<<endl;
}

signed main(){
    fastio;
    
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}