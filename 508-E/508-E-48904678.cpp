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
int main()
{
	int i,j,n,l,r;
	cin>>n;
	int brac[n][2],ans[n]={};
	char out[2*n];
	vector<int> nxt[2];
	for(i=0;i<n;i++){
		cin>>brac[i][0]>>brac[i][1];
		out[2*i] = out[2*i+1] = ' ';
	}

	nxt[0].pb(1);
	for(i=n-1;i>=0;i--)
	{
		nxt[1].pb(1);
		for(auto v:nxt[0])
		{
			if(v<brac[i][0]) continue;
			if(!ans[i] && v<=brac[i][1]) ans[i] = v;
			nxt[1].pb(v+2);
		}
		if(!ans[i]) break;		
		nxt[0].clear();
		swap(nxt[0],nxt[1]);
	}

	if(i!=-1) cout<<"IMPOSSIBLE\n";
	else
	{
		j=0;

		for(i=0;i<n;i++)
		{
			while(out[j]!=' ')j++;
			out[j]='(';
			out[j+ans[i]]=')';
		}

		for(i=0;i<2*n;i++) cout<<out[i];
	}
}