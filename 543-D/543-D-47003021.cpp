//https://codeforces.com/problemset/problem/543/D
#include <iostream>
#include <algorithm>
#include <vector>
#define mod 1000000007
#define lli long long int
using namespace std;
vector <int> graph[200005];
vector <lli> pre[200005];
lli dp[200005],ans[200005];
void dfs1(int u)
{
	dp[u]=1; int i=0;
	for(int v:graph[u]) { pre[u][i++]=dp[u]; dfs1(v); dp[u]=(dp[u]*(dp[v]+1))%mod; }
	lli tmp=1;	for(i=pre[u].size()-1;i>=0;i--) { pre[u][i]=(pre[u][i]*tmp)%mod; tmp=(tmp*(dp[graph[u][i]]+1))%mod; }
}
void dfs2(int u,lli v=0)
{
	ans[u]=(dp[u]*(v+1))%mod;
	for(int i=0;i<pre[u].size();i++)
		dfs2(graph[u][i],(pre[u][i]*(v+1))%mod);
}
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int i,n,p;
	cin>>n;
	for(i=2;i<=n;i++){
		cin>>p;
		pre[p].push_back(1);
		graph[p].push_back(i);
	}
	dfs1(1);	dfs2(1);
	for(i=1;i<=n;i++)
		cout<<ans[i]<<" ";
}