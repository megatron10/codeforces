#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<int> ad[50];
bool visited[50]={};
int i,n,m,a,b,ans=0;
void dfs(int s){   for(int i:ad[s]) {  if(!visited[i]) { visited[i]=1; dfs(i); }	}  }
int main()
{
	cin>>n>>m;
	while(m--)
	{
		cin>>a>>b;
		ad[a-1].push_back(b-1);
		ad[b-1].push_back(a-1);
	}
	for(i=0;i<n;i++){ if(!visited[i]) { visited[i]=1; dfs(i); ans++; } }
	cout<<((1LL)<<(n-ans));
	return 0;
}