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

vector<string> g;
int n,m;
vector<PII> a;
int h[N],l[N];

int get(int i,int j){
	int res=0;
	
	for(int ii=min(a[i].first,a[j].first);ii<max(a[i].first,a[j].first);ii++){
			if(h[ii]) res+=1000000;
			else res++;

	}
	for(int jj=min(a[i].second,a[j].second);jj<max(a[i].second,a[j].second);jj++){
		if(l[jj]) res+=1000000;
		else res++;
	}
	return res;
}

void solve(){
	string s;
	while(cin>>s) g.pb(s);
	n=g.size(),m=g[0].size();
	
	for(int i=0;i<=n;i++) h[i]=1;
	for(int i=0;i<=m;i++) l[i]=1;
	
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++){
			if(g[i][j]=='#') a.pb({i,j}),h[i]=0,l[j]=0;
		}
	
	int res=0;
	for(int i=0;i<a.size();i++){
		for(int j=i+1;j<a.size();j++){
			res+=get(i,j);
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