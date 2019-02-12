#include<bits/stdc++.h>
using namespace std;
typedef int long long ll;
ll check(ll i,ll s)
{
	ll k=i,sum=0;
	while(k>=1)
	{
		sum+=k%10;
		k/=10;
	}
	if(i-sum>=s)
		return 1;
	return 0;
}
int main()
{
	ll n,s,ans=0;
	cin>>n>>s;
	for(ll i=s;i<=min(s+162,n);i++)
	{
		ans+=check(i,s);
	}
	ans+=n-min(s+162,n);
	cout<<ans<<endl;
}