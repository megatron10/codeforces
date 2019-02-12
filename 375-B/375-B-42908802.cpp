#include<iostream>
#include<algorithm>
#include<cmath>
#define IOS ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define lli long long int
#define pr 1000000007
using namespace std;
int n,m,dp[5002][5002]={},dp2[5002][5002]={},counter[5002]={},tmp=0,i=0,j,ans=0;
int main()
{
	IOS
	cin>>n>>m;char c;
	for(i=1;i<=n;i++){ for(j=1;j<=m;j++){cin>>c; dp2[j][dp[i][j]=(dp[i][j]=c-'0')?(1+dp[i][j-1]):0]++; } }
	for(i=1;i<=m;i++) {tmp=0; for(j=m;j;j--)ans=max(ans,(tmp+=dp2[i][j])*j);}
	cout<<ans; 
}