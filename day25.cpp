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
const int N=100010;

vector<int> eg[N];

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
int idx;
int get(string s){
	if(q.count(s)) return q[s];
	q[s]=++idx;
	return q[s];
}

vector<array<int,2>> edge;

#define MAXN 2010

int low[MAXN], dfn[MAXN], dfs_clock;
bool isbridge[MAXN];
int cnt_bridge;
int father[MAXN];
array<int,2> res;

void tarjan(int u, int fa,int l,int r) {
  if(cnt_bridge) return;
  low[u] = dfn[u] = ++dfs_clock;
  for (int i = 0; i < eg[u].size(); i++) {
    int v = eg[u][i];
    if(u==edge[l][1] and v==edge[l][0]) continue;
    if(u==edge[r][1] and v==edge[r][0]) continue;
    if (!dfn[v]) {
      tarjan(v, u,l,r);
      low[u] = min(low[u], low[v]);
      if (low[v] > dfn[u]) {
        isbridge[v] = true;
        ++cnt_bridge;
        res={v,father[v]};
        return;
      }
    } else if (dfn[v] < dfn[u] && v != fa) {
      low[u] = min(low[u], dfn[v]);
    }
  }
}

bool st[N];

int p[MAXN];
int sz[MAXN];

int find(int x){
	if(p[x]!=x) p[x]=find(p[x]);
	return p[x];
}
void merge(int a,int b){
	a=find(a),b=find(b);
	if(a==b) return;
	p[a]=b;
	sz[b]+=sz[a];
}

void dfs(int u,int fa){
	father[u] = fa;
	st[u]=1;
	for(auto x:eg[u]){
		if(st[x]) continue;
		dfs(x,u);
	}
}

void solve(){
	string s;
	
	while(getline(cin,s)){
		auto t=split(s,": ");
		int u=get(t[0]);
		t=split(t[1]," ");
		for(auto x:t){
			int v=get(x);
			eg[u].pb(v);
			eg[v].pb(u);
			edge.pb({u,v});
			cout<<u<<" "<<v<<endl;
		}
	}
	dfs(1,0);
	int m=edge.size();
	for(auto &x:edge){
		if(father[x[1]]==x[0]) swap(x[0],x[1]);
	}
	bool flag=0;
	// for(int i=0;i<m and !flag;i++){
		// for(int j=i+1;j<m and !flag;j++){
			// memset(low,0,sizeof low);
			// memset(isbridge,0,sizeof isbridge);
			// memset(dfn,0,sizeof dfn);
			// dfs_clock=0;
// 			
			// tarjan(1,0,i,j);
			// if(cnt_bridge){
				// cout<<i<<" "<<j<<endl;
				// cout<<edge[i][0]<<" "<<edge[i][1]<<endl;
				// cout<<edge[j][0]<<" "<<edge[j][1]<<endl;
				// cout<<res[0]<<" "<<res[1]<<endl;
				// flag=1;
			// }
		// }
	// }
	
	for(int i=0;i<MAXN;i++) p[i]=i,sz[i]=1;
	for(int i=0;i<m;i++){
		if(edge[i][0]==510 and edge[i][1]==21) continue;
		if(edge[i][0]==1386 and edge[i][1]==675) continue;
		if(edge[i][0]==226 and edge[i][1]==995) continue;
		// if(edge[i][0]==1 and edge[i][1]==4) continue;
		// if(edge[i][0]==7 and edge[i][1]==4) continue;
		// if(edge[i][0]==10 and edge[i][1]==13) continue;
		merge(edge[i][0],edge[i][1]);
	}
	set<int> se;
	int ans=-1;
	for(int i=1;i<=idx;i++){
		int a=find(i);
		if(se.count(a)) continue;
		se.insert(a);
		//cout<<a<<" "<<sz[a]<<endl;
		if(ans==-1) ans=sz[a];
		else ans*=sz[a];
	}
	cout<<ans;
}

signed main(){
    fastio;
    
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}