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
using namespace std;
bool isnp[100001],taken[100001];
vector<int> primes;
vector<int> parts[10000];

int main()
{
	nfs;
	int i,j,n,pairs=0;
	isnp[1] = 1;
	cin>>n;
	for(i=2;i<=sqrt(n);i++)
		if(!isnp[i])
		{
			primes.pb(i);
			parts[primes.size()-1].pb(i);
			for(j=i*i;j<=n;j+=i)
			{
				if(!isnp[j])
				{
					isnp[j] = 1;
					parts[primes.size()-1].pb(j);
				}
			}
		}

	for(;i<=n/2;i++) if(!isnp[i]){ primes.pb(i); parts[primes.size()-1].pb(i); }

	unordered_set<int> x2;
	for(i=2;i<=n;i+=2) x2.insert(i);

	for(i=primes.size()-1;i>0;i--)
	{
		if((parts[i].size()&1) && primes[i]*2<=n)
		{
			parts[i].pb(2*primes[i]);
			x2.erase(2*primes[i]);
		}
		pairs += (parts[i].size())/2;
	}

	pairs += (x2.size())/2;

	cout<<pairs<<endl;
	auto itr=x2.begin();
	for(i=0;i<(x2.size())/2;i++)
		cout<<(*(itr++))<<" "<<(*(itr++))<<"\n";
	
	// cout<<primes.size()<<endl;
	for(i=1;i<primes.size();i++)
		for(j=0;j<(parts[i].size()-1);j+=2)
			cout<<parts[i][j]<<" "<<parts[i][j+1]<<"\n";
		
	
}