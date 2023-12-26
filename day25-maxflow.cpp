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
const int N=100010,M=N,INF=1e9;

vector<string> split(string a,string b){
	int n=a.size(),m=b.size();
	a="#"+a,b="#"+b;
	vector<int> q(n+1,0);
    vector<int> ne(m+1,0);
	for(int i=2,j=0;i<=m;i++){
		while(j and b[j+1]!=b[i]) j=ne[j];
		if(b[j+1]==b[i]) j++;
		ne[i]=j;
	}
	vector<string> res;
	string str="";
	for(int i=1,j=0;i<=n;i++){
		while(j and a[i]!=b[j+1]) j=ne[j];
		if(a[i]==b[j+1]) j++;
		str+=a[i];
		q[i]=j;
		if(j==m){
			j=0;
			res.pb(str.erase(str.size()-m));
			str.clear();
		}
	}
	if(str.size()) res.pb(str);
	return res;
}

map<string,int> q;
int cnt;
int get(string s){
	if(q.count(s)) return q[s];
	q[s]=++cnt;
	return q[s];
}

struct MF {
  int h[N], e[M], ne[M], w[M], cw[M], idx = 0;
  int vis[N];

  int n, S, T;
  LL maxflow = 0;
  int dep[N], cur[N];

  void init() {
    memset(h, -1, sizeof h);
    idx = 0;
  }
  
  void clear(){
	memset(vis,0,sizeof vis);
	maxflow=0;
	memcpy(w,cw,sizeof cw);
	memset(dep,0,sizeof dep);
	memset(cur,0,sizeof cur);
  }

  void add(int a, int b, int c) {
    e[idx] = b, ne[idx] = h[a], cw[idx] = c, h[a] = idx++;
    e[idx] = a, ne[idx] = h[b], cw[idx] = 0, h[b] = idx++;
  }

  bool bfs() {
    queue<int> q;
    memset(dep, -1, sizeof dep);
    dep[S] = 0;
    q.push(S);
    cur[S] = h[S];
    while (q.size()) {
      int u = q.front();
      q.pop();
      for (int i = h[u]; ~i; i = ne[i]) {
        int j = e[i];
        if (dep[j] == -1 and w[i]) {
          dep[j] = dep[u] + 1;
          cur[j] = h[j];
          if (j == T) return 1;
          q.push(j);
        }
      }
    }
    return 0;
  }

  int dfs(int u, int limit) {
    if (u == T or !limit) return limit;
    int flow = 0;
    for (int i = cur[u]; ~i and flow < limit; i = ne[i]) {
      cur[u] = i;
      int j = e[i];
      if (dep[j] == dep[u] + 1 and w[i]) {
        int t = dfs(j, min(limit - flow, w[i]));
        if (!t) dep[j] = -1;
        w[i] -= t;
        w[i ^ 1] += t;
        flow += t;
      }
    }
    return flow;
  }

  void dinic() {
    while (bfs()) {
      // memcpy(cur, h, sizeof h);
      maxflow += dfs(S, INF);
    }
  }
  void dfs(int u) {
	  vis[u] = 1;
	  for (int i = h[u]; ~i; i = ne[i]) {
	    int v = e[i];
	    if (!vis[v] && w[i]) dfs(v);
	  }
  }
} mf;

void solve(){
	string s;
	mf.init();
	while(getline(cin,s)){
		auto t=split(s,": ");
		int u=get(t[0]);
		t=split(t[1]," ");
		for(auto x:t){
			int v=get(x);
			mf.add(u,v,1);
			mf.add(v,u,1);
		}
	}
	int u=1,v=1;
	for(v=2;v<=cnt;v++){
		mf.clear();
		mf.S=u,mf.T=v;
		mf.dinic();
		if(mf.maxflow<4) break;
	}
	mf.dfs(u);
	int res=0;
	for(int i=1;i<=cnt;i++) res+=mf.vis[i];
	res*=(cnt-res);
	cout<<res;
}

signed main(){
    fastio;
    
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}