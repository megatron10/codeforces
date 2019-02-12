#include <iostream>
#include <algorithm>
#include <queue>
#include <cmath>
#include <utility>
using namespace std;
//bool visited[200001]={};
vector <vector<int>>graph(200001);
vector<int> factors;
vector<int> fact_count;
int ans[200001]={},a[200001]={};

void dfs(int u, int h, int pa, int gcd)
{
	int i=0,tmp=0;
	for(i=0;i<factors.size();i++){
		if(!(a[u]%factors[i])) fact_count[i]++;
		if(fact_count[i]>=h) tmp=factors[i];
	}
	// cout<<u<<" : "<<tmp<<endl;
	ans[u]=max(gcd=__gcd(gcd,a[u]),tmp);

	for(int v:graph[u])
		if(v!=pa)
			dfs(v,h+1,u,gcd);

	for(i=0;i<factors.size();i++)
		if(!(a[u]%factors[i])) fact_count[i]--;
	
}
void dfs1(int u)
{
	ans[u]=a[u]; int i,count=0;
	for(i=1;i<=sqrt(a[u]);i++)
	{
		if(!(a[u]%i)){
			factors.push_back(i);
			factors.push_back(a[u]/i);
			count+=2;
		}
	}

	sort(factors.begin(),factors.end());
	for(i=0;i<count;i++)
		fact_count.push_back(1);

	for(int v:graph[u])
		dfs(v,1,u,0);
}
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int u,v,i,n;
	cin>>n;
	for(i=1;i<=n;i++)
		cin>>a[i];

	for(i=1;i<n;i++)
	{
		cin>>u>>v;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}
	dfs1(1);
	for(i=1;i<=n;i++)
		cout<<ans[i]<<" ";
}