//https://codeforces.com/contest/208/problem/E
#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <queue>
#include <cstring>
#define lli long long int
using namespace std;

// bool vis[100011]={};
int timer=0;
vector<int> graph[100011];
vector<int> depths[100011];
int depth[100011]={};
int times[100011][2]={};
int anc[100011][20]={};
int dfs(int u,int pa,int d)
{
	timer++;
	anc[u][0]=pa;
	depth[u]=d;
	times[u][0]=timer;
	depths[d].push_back(timer);
	for(int v:graph[u])
		if(v!=pa)
			dfs(v,u,d+1);
	times[u][1]=timer;
}

int pth_anc(int u,int p,int n){
	int i=0; p<<=1;
	for(i=0;i<=ceil(log2(n));i++)
		u=((p>>=1)&1)?anc[u][i]:u;
	return u;
}

void lca(int n)
{
	int i,j;
	for(i=1;i<=ceil(log2(n));i++)
		for(j=0;j<=n;j++)
			anc[j][i]=anc[anc[j][i-1]][i-1];
}

int main()
{
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	int i,n,u,v,m,p,deep;vector<int> root;
	cin>>n;
	for(i=1;i<=n;i++)
	{
		cin>>v; u=i;
		if(!v) {root.push_back(u);continue;}
		graph[u].push_back(v);
		graph[v].push_back(u);
	}

	for(i=0;i<root.size();i++)
		dfs(root[i],0,1);

	lca(n);

	cin>>m;
	for(i=0;i<m;i++){
		cin>>v>>p;
		u=pth_anc(v,p,n); deep=depth[u]+p;
		if(u) cout<<((upper_bound(depths[deep].begin(),depths[deep].end(),times[u][1])-lower_bound(depths[deep].begin(),depths[deep].end(),times[u][0]))-1)<<endl;
		else cout<<0<<endl;
	}

}