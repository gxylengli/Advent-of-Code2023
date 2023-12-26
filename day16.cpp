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
const int N=112;

int n,m;
vector<string> g;
bool st[N][N];
bool dd[N][N][4];

int get(char c){
	if(c=='d') return 0;
	else if(c=='l') return 1;
	else if(c=='r') return 2;
	return 3;
}

void dfs(int x,int y,char fx,int cnt){
    if(x>=n or x<0 or y>=m or y<0 or dd[x][y][get(fx)]) {
        return;
    }
    st[x][y]=1;
    dd[x][y][get(fx)]=1;
    if(g[x][y]=='/'){
        if(fx=='l') dfs(x-1,y,'d',cnt+1);
        else if(fx=='u') dfs(x,y-1,'r',cnt+1);
        else if(fx=='d') dfs(x,y+1,'l',cnt+1);
        else dfs(x+1,y,'u',cnt+1);
    }else if(g[x][y]=='\\'){
        if(fx=='l') dfs(x+1,y,'u',cnt+1);
        else if(fx=='u') dfs(x,y+1,'l',cnt+1);
        else if(fx=='d') dfs(x,y-1,'r',cnt+1);
        else dfs(x-1,y,'d',cnt+1);
    }else if(g[x][y]=='|'){
    	if(fx=='l' or fx=='r') dfs(x-1,y,'d',cnt+1),dfs(x+1,y,'u',cnt+1);
        else if(fx=='u') dfs(x+1,y,'u',cnt+1);
        else if(fx=='d') dfs(x-1,y,'d',cnt+1);
    }else if(g[x][y]=='-'){
    	if(fx=='u' or fx=='d') {
    		dfs(x,y+1,'l',cnt+1),dfs(x,y-1,'r',cnt+1);
    	}else if(fx=='l') dfs(x,y+1,'l',cnt+1);
        else if(fx=='r') dfs(x,y-1,'r',cnt+1);
    }else{
    	if(fx=='l') dfs(x,y+1,'l',cnt+1);
        else if(fx=='u') dfs(x+1,y,'u',cnt+1);
        else if(fx=='d') dfs(x-1,y,'d',cnt+1);
        else dfs(x,y-1,'r',cnt+1);
    }
}


void solve(){
	string s;
	while(cin>>s){
		g.pb(s);
	}
	n=g.size(),m=g[0].size();

	int ans=0;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(i==0 or j==0 or j==m-1 or i==n-1) ;
			else continue;
			memset(st,0,sizeof st);
			memset(dd,0,sizeof dd);
			dfs(i,j,'l',0);
			int res=0;
			for(int i=0;i<n;i++){
				for(int j=0;j<m;j++) res+=st[i][j];
			}
			ans=max(res,ans);
			
			memset(st,0,sizeof st);
			memset(dd,0,sizeof dd);
			dfs(i,j,'r',0);
			res=0;
			for(int i=0;i<n;i++){
				for(int j=0;j<m;j++) res+=st[i][j];
			}
			ans=max(res,ans);
			
			memset(st,0,sizeof st);
			memset(dd,0,sizeof dd);
			dfs(i,j,'d',0);
			res=0;
			for(int i=0;i<n;i++){
				for(int j=0;j<m;j++) res+=st[i][j];
			}
			ans=max(res,ans);
			
			memset(st,0,sizeof st);
			memset(dd,0,sizeof dd);
			dfs(i,j,'u',0);
			res=0;
			for(int i=0;i<n;i++){
				for(int j=0;j<m;j++) res+=st[i][j];
			}
			ans=max(res,ans);
		}
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