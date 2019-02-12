#include <iostream>
#include <algorithm>
#include <vector>
#define lli long long int
using namespace std;
lli dp[200005][2]={};
lli a[200005]={};
bool x[200005][2]={},vis[200005][2]={}; int n;
lli dfs(int u,bool t)
{
	if(u<=0 || u>n) return 0;
	if(u==1 && t==0) return 0;
	if(dp[u][t]) return dp[u][t];
	if(vis[u][t]) return -1;
	vis[u][t]=1;
	int v=u+(t?a[u]:-a[u]);
	lli r=dfs(v,!t);
	x[u][t]=(r?x[v][!t]:0);
	return dp[u][t]=r+(r==-1?0:a[u]);
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	x[1][0]=1; dp[1][1]=-1; x[1][1]=0;
	int i;
	cin>>n;
	for(i=2;i<=n;i++) cin>>a[i];
	for(i=1;i<n;i++) cout<<(dfs(1+i,0)+(dfs(1+i,0)==-1?0:i)+(x[1+i][0]?i:0))<<endl;	
}