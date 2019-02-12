//https://codeforces.com/contest/519/problem/E
#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <queue>
#include <cstring>
#define lli long long int
using namespace std;

int timer=0,n,val;
vector<int> graph[100011];
int times[100011][2]={},depth[100011]={};
int anc[100011][20]={};
int q[100011]={};
int edge_ans[100011]={};
void dfs(int u,int pa,int d)
{
	timer++;
	anc[u][0]=pa;
	depth[u]=d;
	q[u]=1;
	times[u][0]=timer;
	for(auto v:graph[u])
		if(v!=pa){
			dfs(v,u,d+1);
			q[u]+=q[v];
		}
	times[u][1]=timer;
}


bool is_anc(int u,int v){
	return (!u)||(times[u][0]<=times[v][0] && times[u][1]>=times[v][1]);
}

int lca(int v1,int v2)
{
	int k=1+val,v;
	while(k--){
		v=anc[v1][k];
		if(!is_anc(v,v2))
			v1=v;
	}
	return (!is_anc(v1,v2))?(anc[v1][0]):v1;
}

int query(int v1,int v2)
{
	if(depth[v1]==depth[v2]){
		if(v1==v2)return q[1];
		int k=1+val,v;
		while(k--){
			v=anc[v1][k];
			if(!is_anc(v,v2)){
				v1=v; v2=anc[v2][k];
			}
		}
		return q[1]-q[v1]-q[v2];
	}
	if(depth[v1]<depth[v2])swap(v1,v2);
	int up=((depth[v1]+depth[v2])/2-depth[lca(v1,v2)])-1,v=v1;
	for(int i=0;up && i<=val;i++,up>>=1)
		if(up&1) v=anc[v][i];
	return q[anc[v][0]]-q[v];

}

void pre_lca()
{
	int i,j; anc[0][0]=0;
	for(i=1;i<=val;i++)
		for(j=0;j<=n;j++)
			anc[j][i]=anc[anc[j][i-1]][i-1];
}

int main()
{
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	int i,u,v,v1,v2,k;
	cin>>n; val=ceil(log2(n));
	for(i=1;i<n;i++)
	{
		cin>>u>>v;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}

	dfs(1,0,1);

	pre_lca();

	cin>>k;
	for(i=0;i<k;i++){
		cin>>v1>>v2;
		cout<<(((depth[v1]+depth[v2])%2==0)?(query(v1,v2)):0)<<endl;
	}
}