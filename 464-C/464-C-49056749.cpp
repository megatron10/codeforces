#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <set>
#include <utility>
#include <queue>
#include <tuple>

#define nfs ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long int
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define pr 1000000007
#define N 100001

using namespace std;

ll pow_up(int b, ll e)
{
	ll ans=1,tmp=b%pr; e=e%(pr-1);
	while(e)
	{
		if(e&1)
			ans = (ans * tmp)%pr;
		tmp = (tmp*tmp)%pr;
		e /= 2; 
	}
	return ans;
}

int main()
{
	// nfs;
	int i,n; char d,c; string s;
	pair<int,string> query[N];
	pair<ll,ll> conv[10];//conv,length
	
	for(i=0;i<10;i++)
		conv[i] = mp(i,1);

	cin>>s>>n;
	query[0]=mp(0,s);
	for(i=1; i<=n; i++)
	{
		cin>>d>>c>>c;
		getline(cin,query[i].ss);
		query[i].ff = d - '0';
	}
	for(i=n; i>=0; i--)
	{
		string t = query[i].ss;
		pair<ll,ll> upd = mp(0,0);
		for(int j = t.length()-1; j>=0; j--)
		{
			upd.ff = ( upd.ff + (pow_up(10,upd.ss)*(conv[t[j]-'0'].ff))%pr )%pr;
			upd.ss = ( upd.ss + conv[t[j]-'0'].ss)%(pr-1);
		}
		conv[query[i].ff] = upd;
	}
	cout<<conv[0].ff<<"\n";	
}