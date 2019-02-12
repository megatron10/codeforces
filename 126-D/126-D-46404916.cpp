#include <iostream>
#include <algorithm>
#include <cmath>
#define ull unsigned long long int
using namespace std;
int solve(int n,int* dp,int* dp2,bool *zec,bool save=1){
	if(n<=0)return 1;
	if(save && dp[n])return dp[n];
	else if(!save && dp2[n])return dp2[n];
	int ans=1,exp=1;
	for(int i=n;i;i--){
		if(zec[i]){
			ans=solve(i-2,dp,dp2,zec); exp=0;
			while(--i && zec[i]==exp)exp^=1;
			if(i) {zec[i]=1; ans+=(zec[i-1])?solve(i-1,dp,dp2,zec):solve(i,dp,dp2,zec,0); zec[i]=0;}
			break;
		}
	}
	return (save)?dp[n]=ans:dp2[n]=ans;
}

int main()
{
	ull fibo[101],n; fibo[1]=1; fibo[2]=2;
	int i,j,k,t,tmp,exp=0;
	for(i=3;i<101;i++)
		fibo[i]=fibo[i-1]+fibo[i-2];
	cin>>t;
	while(t--){
		cin>>n;
		int dp[101]={},dp2[101]={};
		bool zec[101]={};
		for(i=100;i;i--)
			if(n>=fibo[i])
				n-=fibo[i],zec[i]=1;
		cout<<solve(100,dp,dp2,zec)<<endl;
	}
}