#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_set>
#define lli long long int
using namespace std;
int main()
{
	lli n,adj[501][501]={},x[501],i,j,k,temp=0;
	unordered_set<int> take_it;
	vector <lli> out;
	cin>>n;
	for(i=1;i<=n;i++)	for(j=1;j<=n;j++)	cin>>adj[i][j];
	for(i=1;i<=n;i++)cin>>x[i];
	for(k=n;k;k--)
	{
		temp=0; take_it.insert(x[k]);
		for(i=1;i<=n;i++)
		{
			bool a=take_it.find(i)!=take_it.end();
			for(j=1;j<=n;j++)
			{
				adj[i][j]=min(adj[i][j],adj[i][x[k]]+adj[x[k]][j]);
				if(a && take_it.find(j)!=take_it.end())temp+=adj[i][j];
			}
		}	
		out.push_back(temp);
	}
	for(i=n-1;i>=0;i--)cout<<out[i]<<" ";
}