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
const int N=510;

int n;
vector<string> s;
vector<vector<int>> q;

int f[N][N];

int dfs(int a,int b,string &str,vector<int> &p){
	int la=str.size(),lb=p.size();
	if(b==lb){
		for(int i=a;i<la;i++){
			if(str[i]=='#') return 0ll;
		}
		return 1ll;
	}
	if(a>=la) return 0ll;
	if(f[a][b]!=-1) return f[a][b]; 
	int res=0;
	
	if(str[a]=='.') return dfs(a+1,b,str,p);
	else if(str[a]=='#'){
		for(int i=a;i<a+p[b];i++){
			if(a+p[b]>la) return 0ll;
			if(str[i]=='.') return 0ll;
		}
		if(a+p[b]<la and str[a+p[b]]=='#') return 0ll;
		return dfs(a+p[b]+1,b+1,str,p);
	}
	res=dfs(a+1,b,str,p);
	for(int i=a;i<a+p[b];i++){
		if(a+p[b]>la) return 0ll;
		if(str[i]=='.') return res;
	}
	if(a+p[b]<la and str[a+p[b]]=='#') return res;

	res+=dfs(a+p[b]+1,b+1,str,p);
	return f[a][b]=res;
}



void solve(){
	string str,t;
	int ma=0;
	while(cin>>str>>t){
		string ss="";
		for(int i=0;i<5;i++) ss+=str+'?';
		ss.pop_back();
		s.pb(ss);
		string b="";
		vector<int> a;
		for(auto x:t){
			if(x==',') a.pb(stoll(b)),b.clear();
			else b+=x; 
		}
		a.pb(stoll(b));
		q.pb(a);
		for(int i=0;i<4;i++){
			for(auto x:a) q.back().pb(x);
		}
	}
	n=s.size();
	int res=0;
	for(int i=0;i<n;i++) {
		for(int i=0;i<N;i++)
			for(int j=0;j<N;j++) f[i][j]=-1;
		int t=dfs(0,0,s[i],q[i]);
		res+=t;
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