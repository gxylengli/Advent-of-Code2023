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

vector<string> g;

map<string,string> q;

int n,m;

int calc(map<char,int> &a){
	string st="in";
	int tt=10;
	while(st!="A" and st!="R"){
		string s=q[st];
		string nt="";
		auto idx=s.find(',');
		while(idx!=-1 and nt.empty()){
			string r=s.substr(0,idx);
			s.erase(0,idx+1);
			int tt=r.find(':');
			string l=r.substr(0,tt);
			r.erase(0,tt+1);
			if(l[1]=='>' and a[l[0]]>stoll(l.substr(2))) nt=r;
			else if(l[1]=='<' and a[l[0]]<stoll(l.substr(2))) nt=r;
			idx=s.find(',');
		}
		if(nt.empty()) nt=s;
		st=nt;
	}
	if(st=="R") return 0;
	int res=0;
	for(auto [c,v]:a) res+=v;
	return res;
}

void solve(){
	string s;
	while(getline(cin,s)){
		if(s=="") break;
		int len=s.find('{');
		string l=s.substr(0,len);
		s.erase(0,len+1);
		s.pop_back();
		q[l]=s;
	}
	int res=0;
	//part1
	// while(getline(cin,s)){
		// map<char,int> cnt;
		// s.erase(0,1),s.pop_back();
		// string str="";
		// auto check=[&](string a){
			// char c=a[0];
			// a.erase(0,2);
			// cnt[c]=stoll(a);
		// };
		// for(auto x:s){
			// if(x==',') check(str),str="";
			// else str+=x;
		// }
		// if(str.size()) check(str);
		// res+=calc(cnt);
	// }
	
	//part2
	
	function<void(string,map<char,int>,map<char,int>)> dfs=[&](string s,map<char,int> ll,map<char,int> rr){
		if(s=="R") return;
		if(s=="A"){
			int ans=-1;
			for(auto [c,v]:ll){
				if(ans==-1) ans=rr[c]-v+1;
				else ans*=rr[c]-v+1;
			}
			res+=ans;
			return;
		}
		string str=q[s];
		string nt="";
		auto idx=str.find(',');
		char lc,bj;
		int lw;
		string ls;
		map<char,int> cl=ll,cr=rr;
		while(idx!=-1 and nt.empty()){
			if(str.find(',')==-1) break;
			string r=str.substr(0,idx);
			str.erase(0,idx+1);
			int tt=r.find(':');
			string l=r.substr(0,tt);
			r.erase(0,tt+1);
			int w=stoll(l.substr(2));
			if(l[1]=='>'){
				int cl=ll[l[0]];
				if(w+1>rr[l[0]]) continue;
				ll[l[0]]=max(ll[l[0]],w+1);
				dfs(r,ll,rr);
				ll[l[0]]=cl;
				rr[l[0]]=min(rr[l[0]],w);
			}else if(l[1]=='<'){
				int cr=rr[l[0]];
				if(w-1<ll[l[0]]) continue;
				rr[l[0]]=min(rr[l[0]],w-1);
				dfs(r,ll,rr);
				rr[l[0]]=cr;
				ll[l[0]]=max(ll[l[0]],w);
			}
			ls=r,lc=l[0],bj=l[1],lw=w;
			idx=str.find(',');
		}
		dfs(str,ll,rr);

		return;
	};
	
	map<char,int> l,r;
	l['x']=l['m']=l['a']=l['s']=1;
	r['x']=r['m']=r['a']=r['s']=4000;
	dfs("in",l,r);
	
	cout<<res;
}

signed main(){
    fastio;
    
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}