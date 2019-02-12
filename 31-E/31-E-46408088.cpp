#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#define ull unsigned long long int
using namespace std;
string s;
int n;
ull p10[19]={};
ull dp[20][20]={};
bool vis[20][20]={};
bool dir[20][20]={};
ull solve(int i,int j)
{
	if(!i && !j)return 0;
	if(vis[i][j])return dp[i][j];
	vis[i][j]=1; dir[i][j]=0; ull m;
	if(i>0)
		dp[i][j]=solve(i-1,j)+((p10[i-1])*(s[2*n-i-j]-'0'));
	if(j>0 && ((m=solve(i,j-1)+(p10[j-1]*(s[2*n-i-j]-'0')))>=dp[i][j])){
		dp[i][j]=m;
		dir[i][j]=1;
	}
	return dp[i][j];
}
int main()
{
	int i,j,k;
	p10[0]=1;
	for(i=1;i<19;i++)
		p10[i]=p10[i-1]*10;
	cin>>n>>s;
	solve(n,n);
	j=k=n;
	while(j||k){
		cout<<((dir[j][k])?'M':'H');
		(dir[j][k])?k--:j--;
	}
}