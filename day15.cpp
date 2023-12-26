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

int get(string s){
	int res=0;
	for(auto x:s){
		res+=int(x);
		res*=17;
		res%=256;
	}
	return res;
}

vector<vector<pair<string,int>>> q(256);

void er(int x,string s){
	auto &t=q[x];
	vector<pair<string,int>> a;
	for(auto c:t){
		if(c.first==s) continue;
		a.pb(c);
	}
	t=a;
}

void is(int x,string s,int cc){
	auto &t=q[x];
	vector<pair<string,int>> a;
	bool flag=0;
	for(auto &c:t){
		if(c.first==s){
			c.second=cc;
			flag=1;
		}
		a.pb(c);
	}
	if(!flag) a.pb({s,cc});
	t=a;
}

void solve(){
	string s;
	cin>>s;
	string str="";
	vector<string> a;
	for(auto x:s){
		if(x==',') a.pb(str),str.clear();
		else str+=x;
	}
	if(str.size()) a.pb(str);
	int res=0;
	for(auto x:a) {
		if(x.back()=='-'){
			x.pop_back();
			int t=get(x);
			er(t,x);
		}else{
			int id=x.find('=');
			string l=x.substr(0,id),r=x.substr(id+1);
			int t=get(l);
			is(t,l,stoi(r));
		}
	}
	for(int i=0;i<256;i++){
		for(int j=0;j<q[i].size();j++){
			auto t=q[i][j];
			res+=(i+1)*(j+1)*t.second;
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