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

vector<PII> a;

void get(int x){
	string s;
	while(x--) cin>>s;
}

void check(vector<PII> &a){
	vector<PII> res;
	sort(all(a));
	int l=-1,r=-1;
	
	for(auto [x,y]:a){
		if(l==-1) l=x,r=y;
		else if(x<=r) r=max(r,y);
		else{
			res.pb({l,r});
			l=x,r=y;
		}
	}
	if(l!=-1) res.pb({l,r});
	
	a=res;
}

void solve(){
	get(1);
	int x;
	while(cin>>x){
		int y;
		cin>>y;
		a.pb({x,x+y-1});
	}
	check(a);
	cin.clear();
	for(int i=1;i<=7;i++){
		get(2);
		
		vector<array<int,3>> q;
		array<int,3> x;
		int j=0;
		while(cin>>x[j++]){
			if(j==3) j=0,q.pb(x);
		}
		vector<array<int,4>> b;
		for(auto [s,l,len]:q){
			b.pb({l,l+len-1,s,s+len-1});
		}
		sort(all(b));
		vector<PII> res;
		
		for(auto [l,r,x,y]:b){
			for(auto &[ll,rr]:a){
				if(ll==-1) continue;
				if(l<ll and r>=ll){
					if(r<rr){
						int d=ll-l;
						res.pb({x+d,y});
						ll=r+1;
					}else{
						int d=ll-l;
						res.pb({x+d,x+d+(rr-ll)});
						ll=-1;
					}
				}else if(l<=rr and r>=ll){
					if(r<rr){
						res.pb({x,y});
						ll=r+1;
						if(l>ll) a.pb({ll,l-1});
					}else{
						int d=rr-l;
						res.pb({x,x+d});
						if(l>ll) rr=l-1;
						else ll=-1;
					}
				}
			}
		}
		
		for(auto [l,r]:a) if(l!=-1) res.pb({l,r});
		
		check(res);
		a=res;
		cin.clear();
	}
	cout<<a[0].first<<endl;
}

signed main(){
    fastio;
    
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}