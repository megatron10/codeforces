#include<iostream>
#include<algorithm>
using namespace std;
int n,m,matrix[501][501]={};
bool visited[501][501]={};
bool valid(int i,int j){return(i>=0 && i<n && j>=0 && j<m && matrix[i][j]==0)?true:false;}
void dfs(int i,int j,int k,int &c)
{
	if(c==k)return;
	matrix[i][j]=2;
	c++;
	if(valid(i-1,j)){dfs(i-1,j,k,c);if(c==k)return;}
	if(valid(i+1,j)){dfs(i+1,j,k,c);if(c==k)return;}
	if(valid(i,j-1)){dfs(i,j-1,k,c);if(c==k)return;}
	if(valid(i,j+1)){dfs(i,j+1,k,c);if(c==k)return;}
}
int main()
{
	char c;
	int k,i,j,count=0,tmp=0;
	cin>>n>>m>>k;
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
			matrix[i][j]=visited[i][j]=0;
			cin>>c;
			if(c=='#'){matrix[i][j]=1;count++;}
		}
	}
	for(i=0;i<n;i++)for(j=0;j<m;j++)if(matrix[i][j]==0)goto start;
	start:
	dfs(i,j,n*m-count-k,tmp);
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
			if(matrix[i][j]==0)cout<<'X';
			else if(matrix[i][j]==1)cout<<'#';
			else cout<<'.';
		}
		cout<<"\n";
	}
}