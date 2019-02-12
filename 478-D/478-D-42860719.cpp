#include<iostream>
#include<algorithm>
#include<cmath>
#define lli long long int
#define pr 1000000007
using namespace std;
int main()
{
	lli r,g,dp[200011]={1},j,ans=0,i,h;cin>>r>>g;
	h=floor((-1+sqrt(1+(8*(r+g))))/2);i=min(r,g);j=max(r,g);r=i;g=j;
	for(i=1;i<=h;i++) for(j=r-i;j>=0;j--) dp[j+i]=(dp[j+i]+dp[j])%pr;
	for(j=max((int)(((h*(h+1))/2)-g),0);j<=r;j++)ans=(ans+dp[j])%pr;

	cout<<ans;
}