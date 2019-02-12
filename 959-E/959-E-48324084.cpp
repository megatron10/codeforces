#include <iostream>
#include <algorithm>
#define ll long long int
using namespace std;
int main()
{
	ll n,ans=0,tmp=1;
	cin>>n; n--;
	while(n)
	{
		ans += ((n+1)/2*tmp);
		n -= (n+1)/2;
		tmp *= 2;
	}
	cout<<ans<<endl;
}