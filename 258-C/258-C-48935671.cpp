#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <unordered_set>
#include <cmath>
#define nfs ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long int
#define pr 1000000007
#define pb push_back
#define lim 100000
using namespace std;
vector<int> fact[100001];
ll ans[100001]={},fans = 0;
void pre()
{
	int i,j;
	for(i=1; i<=lim; i++)
		for(j=i; j<=lim; j+=i)
			fact[j].pb(i);
	for(i=1; i<=lim; i++)
		ans[i] = 1;
}
ll powmod(ll b,ll e)
{
	ll tmp = b%pr,ans = 1;
	while(e)
	{
		if(e&1)
			ans = (ans*tmp)%pr;
		tmp = (tmp*tmp)%pr;
		e /= 2;
	}
	return ans;

}
int main()
{
	nfs;
	pre();
	int i,j,k,n,l,r,a[100001],tmp1,kt;
	cin>>n;

	for(i=0; i<n; i++)
		cin>>a[i];

	sort(a,a+n); a[n] = 100001;

	for(i=1; i<=lim; i++)
	{
		
		k = tmp1 = 0;
		for(j=0; j<fact[i].size(); j++)
		{
			kt = lower_bound(a,a+n+1,fact[i][j]) - a;
			ans[i] = (ans[i] * powmod(tmp1,kt-k))%pr; 
			k = kt;
			tmp1++;
		}
		ans[i] = (ans[i]*((powmod(tmp1,n-k) + (pr - powmod(tmp1-1,n-k))%pr)%pr))%pr;
		fans = (fans + ans[i])%pr;
	}

	cout<<fans<<"\n";

}