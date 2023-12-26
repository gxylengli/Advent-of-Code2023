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

// map<string,int> q={
	// {"red",12},
	// {"green",13},
	// {"blue",14}
// };

void solve(){
	string s;
	//int idx=1,res=0;
	
	int res2=0;
	while(getline(cin,s)){
		g.pb(s);
		// bool flag=1;
		auto r=split(s,": ")[1];
		auto t=split(r,"; ");
		map<string,int> q;
		for(auto str:t){
			auto l=split(str,", ");
			for(auto x:l){
				auto ans=split(x," ");
				string num=ans[0],color=ans[1];
				q[color]=max(q[color],stoi(num));
			}
		}
		int k=-1;
		for(auto [c,v]:q) {
			if(k==-1) k=v;
			else k*=v;
		}
		res2+=k;
		// if(flag) res+=idx;
		// idx++;
	}
	//cout<<res;
	cout<<res2;
	
}

signed main(){
    fastio;
    
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}