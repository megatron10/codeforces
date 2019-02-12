#include <iostream>
#include <algorithm>
#define lli long long int
#define prime 1000000007 
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);  cout.tie(NULL);
	lli i,t,k,a,b,ans[100002][2]={},partial[100002]={};
	cin>>t>>k;
	for(i=1;i<=k;i++)partial[i]=ans[i][1]=1; ans[k][0]=1; partial[k]=2;
	for(;i<100002;i++){ ans[i][1]=partial[i-1]=((ans[i-1][1]+ans[i-1][0])%prime); ans[i][0]=partial[i-k]; }
	for(i=1;i<100001;i++) partial[i]=(partial[i]+partial[i-1])%prime;
	while(t--)
	{
		cin>>a>>b;
		cout<<(prime+((partial[b]-partial[a-1])%prime))%prime<<endl;
	}	
}