#include<iostream>
#include<algorithm>
#define p 1000000007
#define lli long long int
#define sub(a) ans=(((ans-a)%p)+p)%p;
using namespace std;
int main()
{
	lli n,m,ans=0;
	cin>>n>>m;
	ans=((n%p)*(m%p))%p;
	lli k,i=m,j;
	while(i)
	{
		k=n/i;
		j=n/(k+1);
		sub((k*((((((i+j+1)%p)*((i-j)%p))%p)*((p+1)/2))%p))%p);
		i=j;
	}
	cout<<ans;
}