#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;
bool visited[300001]={};
int dp[300001]={},pa[300001]={};
vector <int> graph[300001];

int find_pa(int u){
	return pa[u]=((pa[u]==u)?u:find_pa(pa[u]));
}

void add_edge(int u,int v){
	if(find_pa(v)==find_pa(u))return;
	dp[pa[u]]=max({((dp[pa[u]]+1)/2)+((dp[pa[v]]+1)/2)+1,dp[pa[u]],dp[pa[v]]});
	pa[pa[v]]=pa[u];
}

int dfs(int u,int s){
	pa[u]=s;
	visited[u]=1;
	int c1=-1,c2=-1,t;
	for(int v:graph[u])
		if(!visited[v]){
			t=dfs(v,s);
			dp[u]=max(dp[u],dp[v]);
			if(t>c1){
				swap(c1,c2);
				c1=t;
			}
			else if(t>c2)
				c2=t;			
		}

	dp[u]=max(dp[u],c1+c2+2);
	return c1+1;
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int i,j,n,m,q,u,v; cin>>n>>m>>q;
	
	while(m--){
		cin>>u>>v;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}

	for(i=1;i<=n;i++)
		if(!visited[i])
			dfs(i,i);

	while(q--){
		cin>>j>>u;
		if(j==2){
			cin>>v;
			add_edge(u,v);
		}
		else
			cout<<dp[find_pa(u)]<<endl;
	}
}