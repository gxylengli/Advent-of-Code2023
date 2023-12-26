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
const int N=60;

int n,m;
vector<string> g;
int tp[N];
vector<int> eg[N],reg[N];

map<string,int> q;
int idx;

int get(string s){
	if(q.count(s)) return q[s];
	q[s]=++idx;
	return q[s];
}

void init(string s){
	int t=s[0]=='%' ? 0  : s[0]=='&' ? 1 : 2;
	string str="";
	int u=0;
	for(int i=1;i<s.size();i++){
		if(s[i]==' '){
			if(str.back()==','){
				str.pop_back();
				int x=get(str);
				eg[u].pb(x);
				reg[x].pb(u);	
			}else if(str!="->"){
				u=get(str);
				tp[u]=t;
			}
			str.clear();
		}else str+=s[i];
	}
	if(str.size()){
		int x=get(str);
		eg[u].pb(x);
		reg[x].pb(u);	
	}
}

void solve(){
	string s;
	while(getline(cin,s)) g.pb(s);
	int root=get("roadcaster");
	n=g.size();
	for(int i=0;i<n;i++){
		if(g[i][0]=='b'){
			swap(g[i],g[0]);
			break;
		}
	}
	for(int i=0;i<n;i++) init(g[i]);
	
	map<int,int> mq[N];
	vector<int> cnt(idx+1,0);
	vector<int> st(idx+1,0);
	
	
	//part1
	// auto bfs=[&](){
		// queue<PII> q;
		// q.push({root,0});
		// int r0=0,r1=0;
		// while(q.size()){
			// auto t=q.front();
			// q.pop();
			// auto u=t.first,d=t.second;
			// for(auto x:eg[u]){
				// r0+=d==0,r1+=d==1;
				// if(tp[x]==0){
					// if(d==1) continue;
					// if(st[x]) q.push({x,0}),st[x]=0;
					// else q.push({x,1}),st[x]=1;
				// }else if(tp[x]==1){
					// if(!mq[x].count(u) or mq[x][u]==0){
						// if(d==1) mq[x][u]=1,cnt[x]++;
					// }else{
						// if(d==0) mq[x][u]=0,cnt[x]--;
					// }
					// if(cnt[x]==reg[x].size()) q.push({x,0});
					// else {
						// q.push({x,1});
					// }
				// }
			// }
		// }
		// return make_pair(r0,r1);
	// };
	// int r0=0,r1=0;
	// for(int i=0;i<1000;i++) {
		// auto t=bfs();
		// r0+=t.first,r1+=t.second;
	// }
	//cout<<(r0+1000)*r1<<endl;
	
	
	//part2;
	
	auto bfs=[&](int c){
		queue<PII> q;
		q.push({root,0});
		int r0=0,r1=0;
		while(q.size()){
			auto t=q.front();
			q.pop();
			auto u=t.first,d=t.second;
			if(u==c and d==1) return d;
			for(auto x:eg[u]){
				r0+=d==0,r1+=d==1;
				if(tp[x]==0){
					if(d==1) continue;
					if(st[x]) q.push({x,0}),st[x]=0;
					else q.push({x,1}),st[x]=1;
				}else if(tp[x]==1){
					if(!mq[x].count(u) or mq[x][u]==0){
						if(d==1) mq[x][u]=1,cnt[x]++;
					}else{
						if(d==0) mq[x][u]=0,cnt[x]--;
					}
					if(cnt[x]==reg[x].size()) q.push({x,0});
					else {
						q.push({x,1});
					}
				}
			}
		}
		return -1ll;
	};
	vector<int> bk={26,46,47,33};
	vector<int> ans;
	for(auto x:bk){
		for(int i=1;i<=100000;i++){
			auto t=bfs(x);
			if(t==1){
				ans.pb(i);
				break;
			}
		}
		fill(all(cnt),0),fill(all(st),0);
		for(int i=0;i<N;i++) mq[i].clear();
	}
	int res=1;
	for(auto x:ans) res=lcm(res,x);
	cout<<res;
	
}

signed main(){
    fastio;
    
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}