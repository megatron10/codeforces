#include <algorithm>
#include <iostream>
#include <vector>
#include <unordered_set>
#define lli long long int
using namespace std;
int l=0,edges=0,minm,ver,ver2=123458;
unordered_set <int> super;
lli pa[123457]={};
bool is_imp[123457]={};
vector<int> graph[123457];

void inp_graph(int n)
{
	int u,v;
	for(int i=0;i<n;i++){
		cin>>u>>v;
		graph[u].push_back(v); graph[v].push_back(u);
	}
}

void dfs(int u,bool f=0,int p=0,int d=0)
{
	is_imp[u]=(super.find(u)!=super.end());
	if(is_imp[u] && (d>l||(d==l && u<ver))) { l=d; ver=u; }
	for(int v:graph[u])	if(v!=p) dfs(v,f,u,d+1),is_imp[u]|=is_imp[v];
	edges+=((p&&!f)?int(is_imp[u]):0);
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int i,u,v,n,m,tmp;
	cin>>n>>m;
	inp_graph(n-1);
	for(i=0;i<m;i++) { cin>>tmp; super.insert(tmp); }
	dfs(ver=tmp); dfs(ver2=ver,1);
	cout<<(min(ver,ver2))<<endl<<((edges*2)-l)<<endl;
}