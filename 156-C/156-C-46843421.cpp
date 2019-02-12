#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <cstring>
#define lli long long int
#define mod 1000000007
using namespace std;
lli fact[2601],ifact[2601],inv[2601];
void init()
{
	fact[0]=fact[1]=ifact[0]=ifact[1]=inv[1]=1;
	for(int i=2; i<=2600; ++i)
	{
		fact[i]=(fact[i-1]*i)%mod;
		inv[i]=(mod-((inv[mod%i]*(mod/i))%mod))%mod;
		ifact[i]=(ifact[i-1]*inv[i])%mod;
	}
}
lli C(int n,int r)
{
	return (n>=r && n>=0 && r>=0)?((((fact[n]*ifact[n-r])%mod)*ifact[r])%mod):0LL;
}
lli calc(int s,int n)
{
	lli ans=0;
	for(int i=0;i<=n;++i)
		ans=(mod+(ans+(((i%2)?-1LL:1LL)*((C(n,i))*(C(s-1-26*i,n-1)))%mod))%mod)%mod;
	return ans;
}
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	init();
	int i,t,l,sum,j; string s;
	cin>>t;
	while(t--)
	{
		cin>>s;
		sum=0;
		l=s.length();
		for(i=0;i<l;i++)
			sum+=s[i]-'a'+1;
		cout<<((mod+(calc(sum,l)-1))%mod)<<endl;
	}
}