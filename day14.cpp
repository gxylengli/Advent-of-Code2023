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
int n,m;

void apply(){
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(g[i][j]=='O'){
				int ii=i,k=i-1;
				while(k>=0){
					if(g[k][j]=='.') swap(g[k][j],g[ii][j]),ii=k,k--;
					else break;
				}
			}
		}
	}
	for(int j=0;j<m;j++){
		for(int i=0;i<n;i++){
			if(g[i][j]=='O'){
				int ii=j,k=j-1;
				while(k>=0){
					if(g[i][k]=='.') swap(g[i][k],g[i][ii]),ii=k,k--;
					else break;
				}
			}
		}
	}
	for(int i=n-1;i>=0;i--){
		for(int j=0;j<m;j++){
			if(g[i][j]=='O'){
				int ii=i,k=i+1;
				while(k<n){
					if(g[k][j]=='.') swap(g[k][j],g[ii][j]),ii=k,k++;
					else break;
				}
			}
		}
	}
	for(int j=m-1;j>=0;j--){
		for(int i=0;i<n;i++){
			if(g[i][j]=='O'){
				int ii=j,k=j+1;
				while(k>=0){
					if(g[i][k]=='.') swap(g[i][k],g[i][ii]),ii=k,k++;
					else break;
				}
			}
		}
	}
}

void solve(){
	string s;
	while(cin>>s) g.pb(s);
	n=g.size(),m=g[0].size();
	vector<int> cnt(n,0);
	for(int i=n-1,j=1;i>=0;i--,j++){
		cnt[i]=j;
	}
	vector<int> a;
	auto cp=g;
	for(int i=1;i<=1000;i++){
		apply();
		int res=0;
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				if(g[i][j]=='O'){
					res+=cnt[i];
				}
			}
		}
		a.pb(res);
	}
	
	int l=0,d=0;
	
	for(int i=0;i<1000;i++){
		for(int len=5;len<100 and !l;len++){
			bool flag=1;
			for(int j=i,k=i+len;j<i+len;j++,k++){
				if(a[j]!=a[k]) flag=0;
			}
			if(flag) l=len,d=i;
		}
	}

	int tt=1e9;
	tt-=d;
	tt%=l;
	if(tt==0) tt=l;
	g=cp;
	for(int i=1;i<=tt+d;i++){
		apply();
	}
	int res=0;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(g[i][j]=='O'){
				res+=cnt[i];
			}
		}
	}
	cout<<res<<endl;
	
}

signed main(){
    fastio;
    
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}