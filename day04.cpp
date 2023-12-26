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
			str.erase(str.size()-m);
			if(str.size()) res.pb(str);
			str.clear();
		}
	}
	if(str.size()) res.pb(str);
	return res;
}

vector<string> g; 
vector<int> cnt(N,0);

int qmi(int a,int b){
	int res=1;
	while(b){
		if(b&1) res*=a;
		a*=a;
		b/=2;
	}
	return res;
}

void solve(){
	string s;
	while(getline(cin,s)) g.pb(s);
	
	//part1
	// int res=0;
	// for(auto str:g){
		// auto r=split(str,": ")[1];
		// auto t=split(r," | ");
		// auto pr=split(t[0]," ");
		// auto num=split(t[1]," ");
		// set<int> s;
		// for(auto x:pr) s.insert(stoi(x));
		// int cnt=0;
		// for(auto x:num) if(s.count(stoi(x))) cnt++;
		// if(cnt) res+=qmi(2,cnt-1);
	// }
	// cout<<res;
	
	//part2
	cnt[0]=1;
	int res=0;
	for(int i=1;i<=g.size();i++){
		cnt[i]+=cnt[i-1];
		res+=cnt[i];
		string str=g[i-1];
		auto r=split(str,": ")[1];
		auto t=split(r," | ");
		auto pr=split(t[0]," ");
		auto num=split(t[1]," ");
		set<int> s;
		for(auto x:pr) s.insert(stoi(x));
		int ct=0;
		for(auto x:num) if(s.count(stoi(x))) ct++;
		cnt[i+1]+=cnt[i],cnt[i+1+ct]-=cnt[i];
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