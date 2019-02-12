#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <utility>
#include <cstring>
#include <queue>

#define lli long long int
#define mod 1000000007
#define xx first
#define yy second
using namespace std;
int r,c;
char inp[1001][1001]={};
int vis[1001][1001]={};
int vis2[1001][1001]={};
pair<int,int> start,end_game;
pair<int,int> moves[4]={{-1,0},{1,0},{0,1},{0,-1}};
vector <int> CB_MO(1000001,0);
pair<int,int> operator+(const pair<int,int>& a,const pair<int,int>& b){ return make_pair(a.xx+b.xx,a.yy+b.yy); }
bool is_valid(pair<int,int>& u)
{
	return (u.xx>0 && u.xx<=r && u.yy>0 && u.yy<=c);
}
void bfs1()
{
	pair<int,int> u,v;
	queue < pair<int,int> > b; b.push(end_game); vis[b.front().xx][b.front().yy]=0;
	while(!b.empty())
	{
		u=b.front();
		for(auto mo:moves)
			if(is_valid(v=u+mo) && vis[v.xx][v.yy]==-1 && inp[v.xx][v.yy]!='T')
			{
				vis[v.xx][v.yy]=vis[u.xx][u.yy]+1;
				b.push(v);
			}
		CB_MO[vis[u.xx][u.yy]]+=(inp[u.xx][u.yy]=='E'||inp[u.xx][u.yy]=='S'||inp[u.xx][u.yy]=='T')?0:(inp[u.xx][u.yy]-'0');
		b.pop();	
	}
}
int bfs2()
{
	pair<int,int> u,v;
	queue < pair<int,int> > b; b.push(start); vis[b.front().xx][b.front().yy]=0;
	while(!b.empty())
	{
		u=b.front();
		if(u==end_game)break;
		for(auto mo:moves)
			if(is_valid(v=u+mo) && vis[v.xx][v.yy]==-1 && inp[v.xx][v.yy]!='T')
			{
				vis[v.xx][v.yy]=vis[u.xx][u.yy]+1;
				b.push(v);
			}
		b.pop();	
	}
	return vis[end_game.xx][end_game.yy];
}
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int i,j;
	memset(vis,-1,sizeof(vis));
	cin>>r>>c;
	for(i=1;i<=r;i++)
		for(j=1;j<=c;j++){
			cin>>inp[i][j];
			if(inp[i][j]=='S') start=make_pair(i,j);
			else if(inp[i][j]=='E') end_game=make_pair(i,j);
		}
	bfs1();
	memset(vis,-1,sizeof(vis));
	int d=bfs2();
	for(i=1;i<=d;i++)CB_MO[i]+=CB_MO[i-1];
	cout<<CB_MO[d]<<endl;
}