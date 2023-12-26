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

void solve(){
	string s;
	cin>>s;
	map<string,string> l,r;
	getchar();
	vector<string> q;
	for(int i=1;i<=666;i++){
		string a,b,c;
		a.resize(3);
		b.resize(3);
		c.resize(3);
		scanf("%s = (%s %s)",&a[0],&b[0],&c[0]);
		l[a]=b,r[a]=c;
		if(a[2]=='A') q.pb(a);
		if(b[2]=='A') q.pb(b);
		if(c[2]=='A') q.pb(c);
	}
	
	
	auto check=[&](){
		for(auto x:q) if(x.back()!='Z') return 1;
		return 0;
	};
	vector<int> t;
	
	for(auto x:q){
		int res=0;
		int i=0;
		while(x.back()!='Z'){
			if(i==s.size()) i=0;
			if(s[i]=='L') x=l[x];
			else x=r[x];
			i++;res++;
		}
		t.pb(res);
	}
	int res=-1;
	for(auto x:t){
		if(res==-1) res=x;
		else res=lcm(res,x);

	}
	cout<<res;
}

signed main(){
    //fastio;
    
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}