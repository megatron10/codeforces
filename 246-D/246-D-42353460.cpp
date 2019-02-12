#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
#include <unordered_set>

#define lli long long int
#define p 100000000
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);  cout.tie(NULL);
	int in,n,m,i,u,v,count=1,color[100001]={};
	vector<vector<int>> graph;
	vector<vector<int>> colorg;
	cin>>n>>m;
	colorg.resize(100001); graph.resize(n+1);
	for(i=1;i<=n;i++)
	{
		cin>>in;
		colorg[in].push_back(i);
		color[i]=in;
	}
	for(i=1;i<=m;i++)
	{
		cin>>u>>v;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}int temp=-1,ans=-1;
	for(i=1;i<=100000;i++)
	{
		if(colorg[i].size()==0)continue;
		unordered_set<int> yeah;
		yeah.insert(i);
		for(auto j:colorg[i])
			for(auto k:graph[j])
				if(yeah.find(color[k])==yeah.end())yeah.insert(color[k]);
		if((yeah.size())>temp+1){ ans=i; temp=(((int)(yeah.size()))-1); }	
	}	
	cout<<ans;
}