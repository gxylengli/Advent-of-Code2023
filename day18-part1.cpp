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
const int N=100010;

vector<vector<char>> g(2000,vector<char> (2000,'.'));
vector<vector<int>> color(2000,vector<int> (2000,-1));
vector<vector<int>> st(2000,vector<int> (2000,0));
map<char,int> fx={
	{'U',0},
	{'D',1},
	{'L',2},
	{'R',3}
};
int dx[4]={-1,1,0,0};
int dy[4]={0,0,-1,1};

int cnt=0;
map<string,int> q;
int get(string s){
	if(q.count(s)) return q[s];
	q[s]=++cnt;
	return q[s];
}

void solve(){
	char c;
	int x;
	string s;
	int sx=1000,sy=1000;
	int lx=sx,rx=sx;
	int ly=sy,ry=sy;
	while(cin>>c>>x>>s){
		int t=fx[c],w=get(s);
		for(int i=0;i<x;i++){
			int nx=sx+dx[t],ny=sy+dy[t];
			g[nx][ny]='#';
			color[nx][ny]=w;
			sx=nx,sy=ny;
			lx=min(lx,sx),rx=max(rx,sx);
			ly=min(ly,sy),ry=max(ry,sy);
		}
	}
	queue<PII> q;
	q.push({0,0});
	while(q.size()){
		auto t=q.front();
		q.pop();
		g[t.first][t.second]='*';
		if(st[t.first][t.second]) continue;
		st[t.first][t.second]=1;
		for(int i=0;i<4;i++){
			int nx=t.first+dx[i],ny=t.second+dy[i];
			if(nx>=0 and nx<2000 and ny>=0 and ny<2000 and g[nx][ny]=='.'){
				q.push({nx,ny});
			}
		}
	}
	int res=0;
	for(auto x:g){
		for(auto y:x){
			res+=y!='*';
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