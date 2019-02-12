#include <iostream>
#include <algorithm>
#include <vector>
#define lli long long int
#define mod 1000000007
using namespace std;
lli fact[1001],ifact[1001],inv[1001];

void init()
{
	fact[0]=fact[1]=ifact[0]=ifact[1]=inv[1]=1;
	for(int i=2;i<=1000;i++)
	{
		fact[i]=(fact[i-1]*i)%mod;
		inv[i]=(mod-((mod/i)*inv[mod%i])%mod)%mod;
		ifact[i]=(ifact[i-1]*inv[i])%mod;
	}
}

lli C(int n,int r)
{
	if(r<0 || r>n)return 0;
	return (fact[n]*((ifact[r]*ifact[n-r])%mod))%mod;
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	init();
	int n,m,k; lli ans=0;
	cin>>n>>m>>k;
	ans=(C(n-1,2*k)*C(m-1,2*k))%mod;
	cout<<ans<<endl;
}