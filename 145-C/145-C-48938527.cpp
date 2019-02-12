#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <unordered_map>
#include <cmath>
#define nfs ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long int
#define pr 1000000007
#define pb push_back
#define mp make_pair
#define lim 100001
using namespace std;
ll fact[lim],ifact[lim],inv[lim],ans=0;

void pre()
{
	fact[0] = ifact[0] = fact[1] = ifact[1] = inv[1] = 1;
	for(int i=2; i<lim; i++)
	{
		fact[i] = (fact[i-1]*i)%pr;
		inv[i] = (pr - (((pr/i)*(inv[pr%i]))%pr))%pr;
		ifact[i] = (ifact[i-1] * inv[i])%pr;
	}
}

bool is_lucky(int no)
{
	string s=to_string(no);
	bool luck=1;
	for(int i=0;i<s.length();i++) if(s[i]!='4' && s[i]!='7') { luck=0; break; }
	return luck;
}

ll ncr(int n,int r)
{
	return (n>=r)?(fact[n]*((ifact[r]*ifact[n-r])%pr))%pr:0LL;
}

ll dp[1<<9+1][1<<9+1];
int main()
{
	nfs;
	pre();
	unordered_map<int,int> lucky;
	int sz,i,j,k,n,un=0;
	cin>>n>>k;

	for(i=0; i<n; i++)
	{
		cin>>j;
		if(is_lucky(j))
		{
			if(lucky.count(j)) lucky[j]++;
			else lucky.insert(mp(j,1));
		}
		else un++;
	}

	sz = lucky.size();
	
	for(i=0; i<=sz; i++)
		dp[i][0] = 1;
	
	auto itr = lucky.begin();
	
	for(i=1; i<=sz; itr++,i++)
		for(j=1; j<=min(i,k); j++)
			dp[i][j] = ( dp[i-1][j] + (dp[i-1][j-1]*(itr->second))%pr )%pr;


	for(i = min(un,k); i>=k-sz; i--)
		ans = (ans + (ncr(un,i)*dp[sz][k-i])%pr)%pr;

	cout<<ans;
	
}