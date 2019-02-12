#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_set>
#include <queue>

using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	int i,u,v,n,m,k,count=0;
	cin>>n>>m>>k;
	bool invalid[n+1]={};
	vector<vector<int>> graph(n+1);
	for(i=0;i<m;i++)
	{
		cin>>u>>v;
		if(u==1 || v==1){invalid[u]=invalid[v]=1; count++; continue;}
		graph[u].push_back(v);
		graph[v].push_back(u);
	}
	if(n-1-count<k){cout<<"impossible"; return 0;}
	unordered_set<int> left;	for(i=2;i<=n;i++)left.insert(i);
	count=0;
	for(i=2;i<=n;i++)
	{
		if(!invalid[i] && left.find(i)!=left.end())
		{
			queue<int> bfs;
			bfs.push(i); left.erase(i);
			while(!bfs.empty())
			{
				unordered_set<int> left2;	
				u=bfs.front();bfs.pop();
				for(auto v:graph[u])
				{
					if(left.find(v)!=left.end())
					{
						left2.insert(v);
						left.erase(v);
					}	
				}
				for(auto j:left)bfs.push(j);
				swap(left,left2);
			}
			count++;
			if(left.empty() || count==k)break;
		}
	}
	cout<<((left.empty())?"possible":"impossible")<<endl;
}