#include <iostream>
#include <algorithm>
#include <cstring>
#include <utility>
#include <vector>
#include <queue>
#define lim 200005
#define ll long long int
#define ff first
#define ss second
#define pb push_back
using namespace std;
struct edge{ int v,c,i; bool d; };
int dir[lim],flow[lim];
vector<edge> gr[lim];
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int i,n,m,a,b,c;
	cin>>n>>m;
	memset(dir,-1,sizeof(dir));
	for(i=0; i<m; i++){
		cin>>a>>b>>c;
		gr[a].pb({b,c,i,0}); flow[a] += c; 
		gr[b].pb({a,c,i,1}); flow[b] += c;
	}

	flow[1] = 0;

	for(i=2; i<n; i++)
		flow[i] /= 2;

	queue<int> bfs;
	bfs.push(1);

	while(!bfs.empty())
	{
		int u = bfs.front(); bfs.pop();
		for(auto v : gr[u])
		{
			if(dir[v.i]==-1)
			{
			
				dir[v.i] = v.d;

				if(!(flow[v.v] -= v.c))
					bfs.push(v.v);
			}
		}
	}

	for(i=0; i<m; i++)
		cout<<dir[i]<<"\n";

}