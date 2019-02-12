#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
#include <unordered_set>

#define lli long long int
#define prime 1000000007 
using namespace std;
lli i,n,m,u,v,ans=0; 
vector<vector<int>> graph;
inline void dfs2(int i)
{
	int counter[n+1]={};
	for(int j:graph[i])
		for(int k:graph[j])
			ans+=(i!=k)?counter[k]++:0;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);  cout.tie(NULL);
	cin>>n>>m;
	graph.resize(n+1);
	for(i=0;i<m;i++) { cin>>u>>v; graph[u].push_back(v); }
	for(i=1;i<=n;i++)dfs2(i);
	cout<<ans;	
}