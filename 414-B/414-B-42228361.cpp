#include <iostream>
#include <algorithm>
#define lli long long int
#define prime 1000000007 
using namespace std;
lli n,k,i,j,l,ans[2002][2002]={};
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);  cout.tie(NULL);
	cin>>n>>k;
	ans[0][1]=1;
	for(l=1;l<=k;l++)
		for(i=1;i<=n;i++)
			for(j=i;j<=n;j+=i)
				ans[l][j]=(ans[l][j]+ans[l-1][i])%prime;
	for(i=1;i<=n;i++) ans[k][i]=(ans[k][i-1]+ans[k][i])%prime;
	cout<<ans[k][n];
}