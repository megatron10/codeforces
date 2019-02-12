#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <cstring>
#define lli long long int
#define mod 1000000007
using namespace std;
lli dp[5001][5001]={};
int n,a,b,k;
inline lli deal(lli in)
{
	return (in>=mod)?in-=mod:in;
}
lli calc(int no,int k)
{
	if(no>n || no<=0)return 0;
	if(dp[no][k]!=-1)return dp[no][k];
	int d=abs(no-b)-1;
	if(d==0) return dp[no][k]=0;
	if(no>b) dp[no][k]=deal(deal(deal(calc(no-1,k)+calc(no-1,k-1))+(mod-calc(no,k-1)))+deal(calc(no+d,k-1)+calc(no+d-1,k-1)));
	else dp[no][k]=deal(deal(deal(calc(no+1,k)+calc(no+1,k-1))+(mod-calc(no,k-1)))+deal(calc(no-d,k-1)+calc(no-d+1,k-1)));
	return dp[no][k];
}
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin>>n>>a>>b>>k;
	memset(dp,-1,sizeof(dp));
	for(int i=1;i<=n;i++) dp[i][0]=1;
	for(int i=1;i<=k;i++) dp[b][i]=0;

	cout<<calc(a,k)<<endl;
	// for(int i=0;i<=k;i++){
	// 	for(int j=1;j<=n;j++)
	// 		cout<<dp[j][i]<<" ";
	// 	cout<<endl;
	// }
}