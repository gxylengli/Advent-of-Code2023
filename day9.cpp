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

int check(string s){
	stringstream sin(s);
	vector<vector<int>> b;
	vector<int> a;
	int x;
	set<int> st;
	while(sin>>x) a.pb(x),st.insert(x);
	b.pb(a);
	while(*st.begin()!=0 or st.size()!=1){
		st.clear();
		a.clear();
		auto t=b.back();
		for(int i=1;i<t.size();i++) {
			a.pb(t[i]-t[i-1]);
			st.insert(t[i]-t[i-1]);
		}
		b.pb(a);
	}
	for(auto &x:b) reverse(all(x));
	for(int i=b.size()-1;i>0;i--){
		auto t=b[i].back();
		b[i-1].pb(b[i-1].back()-t);
	}
	
	return b[0].back();
}

void solve(){
	string s;
	int res=0;
	while(getline(cin,s)){
		int t=check(s);
		cout<<t<<endl;
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