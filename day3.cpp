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
const int N=1010;

vector<string> g;
int n,m;

int dx[8]={-1,-1,0,1,1,1,0,-1};
int dy[8]={0,1,1,1,0,-1,-1,-1};

vector<int> get(){
	vector<int> res;
	for(int i=0;i<n;i++){
		string str="";
		bool flag=0;
		for(int j=0;j<m;j++){
			char t=g[i][j];
			if(t>='0' and t<='9'){
				for(int k=0;k<8;k++){
					int nx=i+dx[k],ny=j+dy[k];
					if(nx<0 or nx>=n or ny<0 or ny>=m) continue;
					if(g[nx][ny]!='.' and (g[nx][ny]>'9' or g[nx][ny]<'0'))
						flag=1;
					
				}
				str+=g[i][j];
			}else{
				if(flag) res.pb(stoi(str));
				str="";
				flag=0;
			}
		}
		if(str.size() and flag) res.pb(stoi(str));
	}
	
	return res;
}

int cnt[N][N];
int f[N][N];

vector<int> get2(){
	vector<int> res;
	for(int i=0;i<n;i++){
		string str="";
		bool flag=0;
		set<array<int,2>> q;
		for(int j=0;j<m;j++){
			char t=g[i][j];
			if(t>='0' and t<='9'){
				for(int k=0;k<8;k++){
					int nx=i+dx[k],ny=j+dy[k];
					if(nx<0 or nx>=n or ny<0 or ny>=m) continue;
					if(g[nx][ny]=='*'){
						q.insert({nx,ny});
					}
					
				}
				str+=g[i][j];
			}else{
				if(flag) res.pb(stoi(str));
				if(q.size()){
					for(auto [x,y]:q){
						cnt[x][y]++;
						if(cnt[x][y]==1) f[x][y]=stoi(str);
						else if(cnt[x][y]==2) f[x][y]*=stoi(str);
						else f[x][y]=0;
					}
				}
				str="";
				flag=0;
				q.clear();
			}
		}
		if(str.size() and flag) res.pb(stoi(str));
		if(q.size()){
			for(auto [x,y]:q){
				cnt[x][y]++;
				if(cnt[x][y]==1) f[x][y]=stoi(str);
				else if(cnt[x][y]==2) f[x][y]*=stoi(str);
				else f[x][y]=0;
			}
		}
	}
	
	return res;
}

void solve(){
	string s;
	while(cin>>s) g.pb(s);
	n=g.size(),m=g[0].size();
	
	//part1
	// auto res=get();
	// int sum=0;
	// for(auto x:res) sum+=x;
	// cout<<sum;
	
	//part2
	
	auto res=get2();
	int sum=0;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(cnt[i][j]==2) sum+=f[i][j];
		}
	}
	cout<<sum;
}

signed main(){
    fastio;
    
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}