#include <iostream>
#include <algorithm>
#include <vector>

#define lli long long int
#define p 100001
using namespace std;
bool isnp[p]={};
int i,j,in,n,a[p]={},fac[p]={},ans[p]={},out=0;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);  cout.tie(NULL);
	isnp[1]=fac[1]=1;
	cin>>n;
	for(i=0;i<n;i++){cin>>in; a[in]=1;}
	for(i=2;i<=320;i++)
	{
		if(!isnp[i])
		{
			fac[i]=i;
			for(j=i*i;j<p;j+=i)
				if(!isnp[j]){ isnp[j]=1; fac[j]=i; }
		}
	}
	for(;i<p;i++)if(!isnp[i])fac[i]=i;
	for(i=p-1;i;i--)
	{
		if(!a[i])continue;
		int tmp=i,tmp2;
		vector<int> f;
		while(tmp!=1)
		{
			tmp2=fac[tmp];
			f.push_back(tmp2);
			a[i]=max(ans[tmp2]+1,a[i]);
			while(tmp%tmp2==0)tmp/=tmp2;
		}
		for(auto k:f) ans[k]=a[i];
		out=max(out,a[i]);
	}
	cout<<out;
}