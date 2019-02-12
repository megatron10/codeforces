#include <iostream>
#include <algorithm>
#include <queue>
#include <utility>
using namespace std;
bool visited[500001]={};
vector <vector<int>>graph(500001);
int bfs(int i)
{
	visited[i]=1; int t=0,h=0,count=0;
	queue<pair<int,int>> Q; Q.push(make_pair(i,0));
	while(!Q.empty())
	{
		auto u=Q.front(); Q.pop();
		if(graph[u.first].size()==1)
			{
				if(u.second==h)count++;
				else { t=max(t+count,h+count-1); count=1; h=u.second; }
			}
		for(int v:graph[u.first])
			if(!visited[v])
				visited[v]=1,Q.push(make_pair(v,u.second+1));
	}
	if(h!=0)t=max(t+count,h+count-1);
	return t;
}
int dfs(int u)
{
	visited[u]=1;int t=0;
	for(int v:graph[u])
		if(!visited[v])
			t=max(t,bfs(v));
	return t+1;
}
int main()
{
	int u,v,i,n;
	cin>>n;
	for(i=1;i<n;i++)
	{
		cin>>u>>v;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}
	cout<<dfs(1);
}