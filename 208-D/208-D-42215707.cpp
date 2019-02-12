#include <iostream>
#include <algorithm>
#define lli long long int
#define prime 1000000007 
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);  cout.tie(NULL);
	lli temp=0,i,j,n,inp[51],cost[5],count[5]={};
	cin>>n;
	for(i=0;i<n;i++)cin>>inp[i];
	for(i=0;i<5;i++)cin>>cost[i];
	for(i=0;i<n;i++)
	{
		temp+=inp[i];
		for(j=4;j>=0;j--){count[j]+=temp/cost[j]; temp%=cost[j];}
	}
	for(i=0;i<5;i++)cout<<count[i]<<" ";
	cout<<"\n"<<temp;
}