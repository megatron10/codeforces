#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#define lli long long int
using namespace std;
struct edge{
	int u,v,c;
	edge(int ui,int vi,int ci){u=ui; v=vi; c=ci;}
	bool operator<(const edge&b){return (this->c)>b.c;}
};
vector <edge> all;
int pa[100001],a[100001],sz[100001];
int find_pa(int u) { return pa[u]=(pa[u]==u)?u:find_pa(pa[u]); }
int main()
{
	lli ans=0; int i,n,m,u,v;
	cin>>n>>m;
	for(i=1;i<=n;i++)  {  cin>>a[i];  pa[i]=i;  sz[i]=1; }
	for(i=0;i<m;i++){ cin>>u>>v; all.push_back({u,v,min(a[u],a[v])}); }
	sort(all.begin(),all.end());
	for(i=0;i<m;i++){
		edge &t=all[i];
		if(find_pa(t.u)==find_pa(t.v))continue;
		u=find_pa(t.u); v=find_pa(t.v);
                ans+=(sz[u]*(1LL*sz[v]))*(t.c);
		if(sz[u]<sz[v])swap(u,v);
		pa[v]=u; sz[u]+=sz[v];
	}
	printf("%.6lf",(ans/(double)((n*(1LL*(n-1)))/2)));
}