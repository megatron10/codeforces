#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <set>
#include <cmath>
#include <utility>
#define nfs ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long int
#define pr 1000000007
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define lim 100000
using namespace std;
vector<ll> fact;
vector<int> f2[7000];
vector<int> heck(ll k,ll n)
{
	if(k==0) return vector<int>(1,fact.size()-1);
	vector<int> ret,get,pos(fact.size()); int i,j,kl;
	if(k&1)
	{
		get = heck(k-1,n);
		for(i=0; i<get.size(); i++)
		for(j=0; j<f2[get[i]].size() && ret.size()<n; j++)
			ret.pb(f2[get[i]][j]);
	}
	else
	{
		get = heck(k>>1,n); int j=0;
		for(i=0; i<get.size() && j<fact.size(); i++) if(get[i]==j) pos[j++]=i;
		
		for(i=0; i<get.size(); i++)
		for(j=0; j<f2[get[i]].size(); j++){
			int el= f2[get[i]][j];
			int l = el? (pos[el-1] + 1) : 0;
			int r = pos[el];
			for(kl=l; kl<=r && ret.size()<n; kl++)
				ret.pb(get[kl]);
		}
		

	}
	return ret;

}
int main()
{
	nfs;
	ll X,k; int i,j;
	cin>>X>>k;
	for(i=1; i<sqrt(X); i++)
		if(X%i == 0)
		{
			fact.pb(X/i);
			fact.pb(i);
		}
	if((1LL*i)*i==X)fact.pb(i);
	
	sort(fact.begin(),fact.end());
	for(i=0; i<fact.size(); i++) for(j=0; j<=i; j++) if(fact[i]%fact[j]==0) f2[i].pb(j);

	vector<int> ans = heck(k,lim);

	for(i=0; i<ans.size(); i++)
		cout<<fact[ans[i]]<<" ";
}