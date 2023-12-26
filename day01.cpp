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

vector<string> g;

map<string,int> q={
	{"one",1}, {"two",2}, {"three",3},{"four",4},{"five",5},{"six",6},{"seven",7},{"eight",8},{"nine",9}
};

int get(string s){
	int l=-1,r=-1;
	for(int i=0;i<s.size() and l==-1;i++){
		if(s[i]>='0' and s[i]<='9') l=s[i]-'0';
		else{
			for(auto [x,v]:q){
				int len=x.size();
				if(i+len>=s.size()) continue;
				string t=s.substr(i,len);
				if(t==x) l=v;
			}
		} 
	}
	for(int i=s.size()-1;i>=0 and r==-1;i--){
		if(s[i]>='0' and s[i]<='9') r=s[i]-'0'; 
		else{
			for(auto [x,v]:q){
				int len=x.size();
				if(i-len+1<0) continue;
				string t=s.substr(i-len+1,len);
				if(t==x) r=v;
			}
		}
	}
	return l*10+r;
}

void solve(){
	string s;
	while(cin>>s) g.pb(s);
	int res=0;
	for(int i=0;i<g.size();i++) {
		res+=get(g[i]);
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