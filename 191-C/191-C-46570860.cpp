//https://codeforces.com/contest/191/problem/C
#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <queue>
#include <cstring>
#define lli long long int
using namespace std;

int timer=0,n;
vector< pair<int,int> > graph[100011];
int times[100011][2]={};
int anc[100011][20]={};
int q[100011]={};
int edge_ans[100011]={};
void dfs(int u,int pa)
{
	timer++;
	anc[u][0]=pa;
	times[u][0]=timer;
	for(auto v:graph[u])
		if(v.first!=pa)
			dfs(v.first,u);
	times[u][1]=timer;
}

void dfs2(int u,int edge_no=0)
{
	for(auto v:graph[u])
		if(v.first!=anc[u][0]){
			dfs2(v.first,v.second);
			q[u]+=q[v.first];
		}

	edge_ans[edge_no]=q[u];
}

bool is_anc(int u,int v){
	return (!u)||(times[u][0]<=times[v][0] && times[u][1]>=times[v][1]);
}

int lca(int v1,int v2)
{
	int k=1+int(ceil(log2(n))),v;
	while(k--){
		v=anc[v1][k];
		if(!is_anc(v,v2))
			v1=v;
	}
	return (!is_anc(v1,v2))?(anc[v1][0]):v1;
}

void pre_lca()
{
	int i,j; anc[0][0]=0;
	for(i=1;i<=ceil(log2(n));i++)
		for(j=0;j<=n;j++)
			anc[j][i]=anc[anc[j][i-1]][i-1];
}

int main()
{
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	int i,u,v,v1,v2,k;
	cin>>n;
	for(i=1;i<n;i++)
	{
		cin>>u>>v;
		graph[u].push_back(make_pair(v,i));
		graph[v].push_back(make_pair(u,i));
	}

	dfs(1,0);

	pre_lca();

	cin>>k;
	for(i=0;i<k;i++){
		cin>>v1>>v2;
		u=lca(v1,v2);
		q[v1]++; q[v2]++; q[u]-=2;
	}


	dfs2(1,0);
	for(i=1;i<n;i++)
		cout<<edge_ans[i]<<" ";

}