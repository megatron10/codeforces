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
	cin>>n>>m;
	vector<vector<int>> graph(n+1);
	bool keep[n+1]={};
	for(i=0;i<m;i++)
	{
		cin>>u>>v;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}
	vector<int> ans;
	unordered_set<int> left;	for(i=1;i<=n;i++)left.insert(i);
	for(i=1;i<=n;i++)
	{
		if(left.find(i)!=left.end())
		{
			count=0;
			queue<int> bfs;
			bfs.push(i); left.erase(i);
			while(!bfs.empty())
			{
				count++;
				u=bfs.front();bfs.pop();
				for(auto v:graph[u]) keep[v]=1;	
				unordered_set<int>::iterator itr=left.begin();
				while(itr!=left.end())
				{
					v=*itr; itr++;
					if(!keep[v]){ bfs.push(v); left.erase(v); }
					keep[v]=0;
				}
			}			
			ans.push_back(count);
			if(left.empty())break;
		}
	}
	sort(ans.begin(),ans.end());
	cout<<ans.size()<<endl;
	for(i=0;i<ans.size();i++)cout<<ans[i]<<" ";
}