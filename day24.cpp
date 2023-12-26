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

vector<array<int,3>> idx,v;

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

int get(int i,int j,double l,double r){
	double k1=(double)v[i][1]/(double)v[i][0];
	double k2=(double)v[j][1]/(double)v[j][0];
	
	double b1=(double)idx[i][1]-k1*idx[i][0];
	double b2=(double)idx[j][1]-k2*idx[j][0];
	
	double x=(b2-b1)/(k1-k2);
	double y=k1*x+b1;
	
	bool flag=1;
	if(x>idx[i][0] and v[i][0]<0) flag=0;
	if(x<idx[i][0] and v[i][0]>0) flag=0;
	if(x>idx[j][0] and v[j][0]<0) flag=0;
	if(x<idx[j][0] and v[j][0]>0) flag=0;
	if(y>idx[i][1] and v[i][1]<0) flag=0;
	if(y<idx[i][1] and v[i][1]>0) flag=0;
	if(y>idx[j][1] and v[j][1]<0) flag=0;
	if(y<idx[j][1] and v[j][1]>0) flag=0;
	
	return x>=l and x<=r and y>=l and y<=r and flag;
}

void solve(){
	string s;
	while(getline(cin,s)){
		auto t=split(s," @ ");
		auto q=split(t[0],", ");
		array<int,3> a; 
		for(int i=0;i<3;i++) a[i]=stoll(q[i]);
		idx.pb(a);
		q=split(t[1],", ");
		for(int i=0;i<3;i++) a[i]=stoll(q[i]);
		v.pb(a);
	}
	int n=idx.size();
	int res=0;
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++) {
			res+=get(i,j,200000000000000,400000000000000);
			res+=get(i,j,7,27);
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