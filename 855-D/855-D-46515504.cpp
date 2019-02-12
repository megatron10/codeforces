#include<iostream>
#include<algorithm>
#include <cmath>
#include <vector>
#include <utility>
#define lli long long int
using namespace std;
//0 special case, 1 part
bool vis[100001][2]={};
int times[100001][2][2]={};
vector<int> graph[100001][2];
int pa[100001][2]={};
int timer[2]={};
void dfs(int u,int papa,bool part)
{
	timer[part]++;
	pa[u][part]=papa;
	vis[u][part]=1;
	times[u][0][part]=timer[part];
	
	for(int v:graph[u][part])
		if(!vis[v][part])
			dfs(v,u,part);
	
	times[u][1][part]=timer[part];
	timer[part]++;
}

int find_pa(int u,bool part){
	return pa[u][part]=(pa[u][part]==u)?u:find_pa(pa[u][part],part);
}

bool is_anc(int u,int v,bool part){
	return (find_pa(u,part)==find_pa(v,part))&&(times[u][0][part]<=times[v][0][part] && times[u][1][part]>=times[v][1][part]);
}

int main()
{
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	int n,i,parenti,typei,q,d,u,v;
	cin>>n;
	for(i=1;i<=n;i++){
		cin>>parenti>>typei;
		if(typei!=-1)graph[parenti][typei].push_back(i);
	}

	for(i=1;i<=n;i++){
		if(!vis[i][0]) dfs(i,i,0);
		if(!vis[i][1]) dfs(i,i,1);
	}

	cin>>q;
	while(q--){
		cin>>d>>u>>v;
		if(d==1)
			cout<<((u!=v && (is_anc(u,v,0)))?"YES":"NO")<<endl;
		else{
			int upv=find_pa(v,1); int upu=find_pa(u,0);
			cout<<((u!=v && ((upv!=v && is_anc(upv,u,0))||(upu!=v&&is_anc(upu,v,1))))?"YES":"NO")<<endl;
		}
	}
}