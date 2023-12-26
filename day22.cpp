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

int st[300][300][300];
int ct[300][300][300];

struct Node{
	int a,b,c,x,y,z;
	Node(int a,int b,int c,int x,int y,int z):a(a),b(b),c(c),x(x),y(y),z(z){};
	bool operator < (const Node &W){
		return c<W.c;
	}
};
vector<Node> q;

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

int idx=0;

void add(Node t,int id){
	for(int i=min(t.a,t.x);i<=max(t.a,t.x);i++){
		for(int j=min(t.b,t.y);j<=max(t.b,t.y);j++){
			for(int k=min(t.c,t.z);k<=max(t.c,t.z);k++) st[i][j][k]=id;
		}
	}
}

bool check(Node t){
	if(t.c==1) return 0;
	int cnt=0;
	for(int i=min(t.a,t.x);i<=max(t.a,t.x);i++){
		for(int j=min(t.b,t.y);j<=max(t.b,t.y);j++){
			cnt+=st[i][j][t.c-1]!=0;
		}
	}
	return cnt==0;
}

void solve(){
	string s;
	int ma=0;
	while(cin>>s) {
		auto a=split(s,"~");
		auto l=split(a[0],",");
		auto r=split(a[1],",");
		q.pb(Node(stoi(l[0]),stoi(l[1]),stoi(l[2]),stoi(r[0]),stoi(r[1]),stoi(r[2])));
		ma=max((abs(q.back().a-q.back().x)+1)*(abs(q.back().b-q.back().y)+1)*(abs(q.back().c-q.back().z)+1),ma);
	}
	for(auto &t:q){
		if(t.z<t.c){
			swap(t.a,t.x),swap(t.b,t.y),swap(t.c,t.z);
		}
		add(t,++idx);
	}
	sort(all(q));
	idx=1;
	for(auto &t:q){
		while(check(t)){
			add(t,0);
			t.c--,t.z--;
			add(t,idx);
		}
		idx++;
	}
	sort(all(q));
	int res=0;
	int idx=0;
	for(int i=0;i<q.size();i++){
		auto t=q[i];
		add(t,0);
		vector<Node> cp;
		for(auto cc:q) cp.pb(cc);
		for(int j=0;j<cp.size();j++){
			auto &tt=cp[j];
			if(j==i) continue;
			while(check(tt)){
				add(tt,0);
				tt.c--,tt.z--;
				add(tt,j+1);
			}
			if(tt.c!=q[j].c) res++;
		}
		for(int j=0;j<cp.size();j++){
			auto &tt=cp[j];
			if(j==i) continue;
			add(tt,0);
		}
		for(int j=0;j<q.size();j++){
			auto tt=q[j];
			add(tt,j+1);
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