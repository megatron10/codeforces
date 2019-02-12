#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;
struct edge{
	int u,v,w;
	edge(int ui=0,int vi=0,int wi=0)
	{
		u=ui; v=vi; w=wi;
	}
};
struct data{
	int n[2]={0,0},w[2]={0,-1};
	data(){
		n[0]=n[1]=w[0]=0;w[1]=-1;
	}
};
bool operator<(edge& a, edge& b){
	return a.w<b.w;
}
int update(edge& t,data dp[]){
	data &v=dp[t.v];
	data &u=dp[t.u];
	bool r=(u.w[0]==t.w);
	if(v.w[0]==t.w)
		v.n[0]=max(v.n[0],u.n[r]+1);
	else if(u.n[r]+1>v.n[0]){
		v.n[1]=v.n[0];    v.w[1]=v.w[0];
		v.n[0]=u.n[r]+1;  v.w[0]=t.w;			
	}
	return v.n[0];
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int ans=0,i,j,n,m,u,v,w; cin>>n>>m; data dp[n+1]={}; vector<edge> edges;
	
	while(m--){
		cin>>u>>v>>w;
		edges.push_back({u,v,w});
	}

	sort(edges.begin(),edges.end());
	
	for(i=0;i<edges.size();i++)
		ans=max(update(edges[i],dp),ans);

	cout<<ans<<endl;
}