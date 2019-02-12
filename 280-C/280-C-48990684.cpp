#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <set>
#include <cmath>
#include <utility>
#define nfs ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long int
#define pr 1000000007
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define lim 100001
using namespace std;
vector<int> gr[lim];
double ans=0.0;
void dfs(int u = 1, int pa = 0, int n = 0)
{
	ans += 1.0/(++n);
	for(auto v:gr[u]) if(v!=pa) dfs(v,u,n);
}
int main()
{
	nfs;
	int i,n;
	cin>>n;
	for(i=1;i<n;i++){
		int u,v;
		cin>>u>>v;
		gr[u].pb(v);
		gr[v].pb(u);
	}
	dfs();
	printf("%.6lf",ans);

}