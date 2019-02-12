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
#define lim 100001
using namespace std;
bool isnp[lim];
unordered_set<int> primes;
ll inv[lim];
void pre()
{
	int i,j;
	isnp[1] = 1;
	for(i=2; i<=sqrt(lim); i++)
		if(!isnp[i]){
			primes.insert(i);
			for(j=i*i; j<lim; j+=i)
				isnp[j]=1;
		}
	for(; i<lim; i++) if(!isnp[i]) primes.insert(i);
}
void prep(ll m)
{
	inv[1]=1;
	for(int i=2; i<m; i++)
		inv[i] = (m-((inv[m%i]*(m/i))%m))%m;
}
int main()
{
	nfs;
	pre();
	int i,n;
	cin>>n;
	if(n==1) cout<<"YES\n1";
	else if(n==4) cout<<"YES\n1\n3\n2\n4";
	else{
		if(primes.count(n))
		{
			prep(n);
			cout<<"YES\n1\n";
			for(i=1;i<n-1;i++)
				cout<<(inv[i]*(i+1))%n<<"\n";
			cout<<n;
		}
		else
			cout<<"NO";
	}
}