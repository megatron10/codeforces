#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
#include <unordered_set>

#define lli long long int
#define p 100000000
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);  cout.tie(NULL);
	int n1,l,n2,k1,k2,i,j; lli ans[203][104][2]={};ans[0][0][0]=ans[0][0][1]=1;
	cin>>n1>>n2>>k1>>k2;
	for(i=1;i<=n1+n2;i++)
	{
		for(l=max(0,i-n2);l<=min(i,n1);l++)
		{
			for(j=1;j<=min(k1,l);j++)ans[i][l][0]=(ans[i][l][0]+(ans[i-j][l-j][1]))%p;
			for(j=1;j<=min(i-l,k2);j++)ans[i][l][1]=(ans[i][l][1]+(ans[i-j][l][0]))%p;
		}
	}	
	cout<<(ans[n1+n2][n1][0]+ans[n1+n2][n1][1])%p;
}