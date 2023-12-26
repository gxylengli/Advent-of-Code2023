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

int a[N],b[N];

void solve(){
	string s;
	cin>>s;
	int n=4;
	for(int i=1;i<=n;i++) cin>>a[i];
	
	string t="";
	for(int i=1;i<=n;i++) t+=to_string(a[i]);
	a[1]=stoll(t);
	cin>>s;
	for(int i=1;i<=n;i++) cin>>b[i];
	t.clear();
	for(int i=1;i<=n;i++) t+=to_string(b[i]);
	b[1]=stoll(t);

	int ans=1;
	for(int i=1;i<=1;i++){
		int res=0;
		for(int j=0;j<=a[i];j++){
			int v=j;
			int d=v*(a[i]-j);
			if(d>b[i]) res++;
		}
		ans*=res;
	}
	cout<<ans;
}

signed main(){
    fastio;
    
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}