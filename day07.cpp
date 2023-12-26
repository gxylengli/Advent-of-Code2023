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

vector<pair<string,int>> q;
map<char,int> rk={
	{'A',13},
	{'K',12},
	{'Q',11},
	{'J',0},
	{'T',9},
	{'9',8},
	{'8',7},
	{'7',6},
	{'6',5},
	{'5',4},
	{'4',3},
	{'3',2},
	{'2',1}
};

int get(string s){
	map<char,int> qq;
	int cnt=0;
	for(auto x:s) {
		if(x!='J') qq[x]++;
		else cnt++;
	}
	if(cnt==5 or qq.size()==1) return 7;
	vector<int> a;
	for(auto [c,v]:qq) a.pb(v); 
	sort(all(a));
	if(a.size()==2){
		if(a[0]==1) return 6;
		if(a[0]==2) return 5;
	}else if(a.size()==3){
		if(a[2]==a[1] and a[1]==2) return 3;
		return 4;
	}else if(a.size()==4) return 2;
	return 1;
}

bool check(string a,string b){
	for(int i=0;i<5;i++){
		int l=rk[a[i]],r=rk[b[i]];
		if(l==r) continue;
		return l<r;
	}
	return 1;
}

bool cmp(pair<string,int> a,pair<string,int> b){
	auto l=a.first,r=b.first;
	int rl=get(l),rr=get(r);
	if(rl!=rr) return rl<rr;
	return check(l,r);
}

void solve(){
	string s;
	int x;
	while(cin>>s>>x){
		q.pb({s,x});
	}
	
	sort(all(q),cmp);
	
	LL res=0;
	for(int i=0;i<q.size();i++){
		res+=(i+1)*q[i].second;
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