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

vector<vector<string>> g;

int getr(vector<string> &a){
	int n=a.size(),m=a[0].size();
	for(int i=0;i<n-1;i++){
		int cnt=0;
		for(int l=i,r=i+1;l>=0 and r<n;l--,r++){
			for(int j=0;j<m;j++) if(a[l][j]!=a[r][j]) cnt++;
		}
		if(cnt==1) return i+1;
	}
	return -1;
}

int getl(vector<string> &a){
	int n=a.size(),m=a[0].size();
	for(int j=0;j<m-1;j++){
		int cnt=0;
		for(int l=j,r=j+1;l>=0 and r<m;l--,r++){
			for(int i=0;i<n;i++) if(a[i][l]!=a[i][r]) cnt++;
		}
		if(cnt==1) return j+1;
	}
	return -1;
}

void solve(){
	string s;
	vector<string> a;
	while(getline(cin,s)){
		if(s.size()==0) g.pb(a),a.clear();
		else a.pb(s);
	}
	g.pb(a);
	int l=0,r=0;
	for(int i=0;i<g.size();i++){
		int t=getl(g[i]);
		if(t==-1) t=getr(g[i]),r+=t;
		else l+=t;
	}
	cout<<r*100+l;
}

signed main(){
    fastio;
    
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}