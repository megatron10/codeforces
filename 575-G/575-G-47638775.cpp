#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <unordered_set>
using namespace std;
struct ed { int v,c;};
vector <ed> graph[100001];
unordered_set <int> endp;
vector<int> up[2];
vector< pair<int,int> > ups;
int ch[100001],dp[100001],dp2[100001];
string cost=""; vector<int> path; int length=0;//output
void go_bfs()
{
	dp[0]=0;
	queue<int> bfs; bfs.push(0);
	while( !bfs.empty() ){
		int u = bfs.front(); bfs.pop();
		for(auto v:graph[u])
			if(!dp[v.v] && v.v){
				dp[v.v] = dp[u] + 1;
				bfs.push(v.v);
			}
	}
}

void mark_end(int u){
	queue<int> bfs; bfs.push(u); endp.insert(u); ch[u]=-1; dp2[u]=0;
	while( !bfs.empty() ){
		u = bfs.front(); bfs.pop();
		for(auto v:graph[u])
			if(!v.c && endp.find(v.v)==endp.end()){
				ch[v.v]=u; dp2[v.v]=dp2[u]+1;
				endp.insert(v.v);
				bfs.push(v.v);
			}
	}
}

void go_up(){
	while(!up[0].empty() && up[0][0]!=0){
		int minm=10; for(auto u:up[0]) for(auto v:graph[u]) if(dp[v.v] == dp[u] - 1) minm=min(minm,v.c);
		cost=cost+to_string(minm);
		for(auto u:up[0]) for(auto v:graph[u]) if(minm==v.c && dp[v.v] == dp[u] - 1 && !ch[v.v]) { up[1].push_back(v.v); ch[v.v]=u; }
		up[0].clear();
		swap(up[0],up[1]);	
	}
}

void go_down_and_dance(int n){
	int u=0; path.push_back(u);
	while(u!=n-1) path.push_back(u=ch[u]);
	cout<<cost<<endl<<path.size()<<endl;
	for(auto v:path) cout<<v<<" "; cout<<endl;
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int i,n,m,u,v,c; int minm=1000000;
	cin>>n>>m;
	
	for(i=1;i<=m;i++){
		cin>>u>>v>>c;
		graph[u].push_back({v,c});
		graph[v].push_back({u,c});
	}

	mark_end(n-1);
	go_bfs();
	for(auto p:endp) if(dp[p]) minm=min(minm,dp[p]);
	for(auto p:endp) if(dp[p]==minm) ups.push_back(make_pair(dp2[p],p));
	sort(ups.begin(),ups.end());
	for(auto pt:ups) up[0].push_back(pt.second);
	go_up();
	go_down_and_dance(n);
}