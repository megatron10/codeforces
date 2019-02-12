#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <queue>
#define lli long long int
using namespace std;
lli dp[100005][2]={};
lli a[100005];
vector <int> graph[100005];
void dfs(int u,int pa)
{
	for(int v:graph[u])
		if(v!=pa){
			dfs(v,u);
			dp[u][0]=max(dp[u][0],dp[v][0]);
			dp[u][1]=max(dp[u][1],dp[v][1]);
		}
	int t=a[u]+dp[u][1]-dp[u][0];
	(t>0)?dp[u][0]+=t:dp[u][1]-=t;
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int i,n,m,u,v;
	cin>>n;
	for(i=1;i<n;i++){ cin>>u>>v; graph[u].push_back(v);	graph[v].push_back(u);	}
	for(i=1;i<=n;i++) cin>>a[i];
	dfs(1,0);
	cout<<(dp[1][0]+dp[1][1])<<endl;
}