#include <iostream>
#include <algorithm>
#include <unordered_set>
#define lli long long int
#define prime 1000000007
using namespace std;
int main()
{
	int i,n,p[1011]={},pre[1011]={},ans=0;cin>>n;
	for(i=1;i<=n;i++)cin>>p[i];
	for(i=1;i<=n;i++) pre[i]=(prime+2+((2*pre[i-1])%prime)-pre[p[i]-1])%prime;
	cout<<pre[n];
}