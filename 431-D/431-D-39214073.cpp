#include <iostream>
#include <algorithm>
#define ulli unsigned long long int
using namespace std;
ulli nCr[65][66];
int k;
void build()
{
	int i,j;
	nCr[0][0]=1;
	for(i=1;i<65;i++)
	{
		nCr[i][0]=nCr[i][i]=1;
		for(j=1;j<i;j++)nCr[i][j]=nCr[i-1][j-1]+nCr[i-1][j];
	}
}
int kitni_bits(ulli no)
{
	int ret=0;
	while(no)
	{
		if(no&1)ret++;
		no>>=1;
	}
	return ret;
}
ulli solve(ulli no)
{
	int pos=0;
	int shift=k-kitni_bits(no);
	for(;0>shift;shift++)no=no^(no&(-no));
	ulli answer=0;
	while(no)
	{
		if(no&1)
		{
			int r=shift;
			answer+=((pos>=r)?nCr[pos][r]:0);
			shift++;
		}
		no>>=1;
		pos++;
	}
	return answer;
}
int main() 
{
	build();
	ulli m,ans,l,r,mid,temp;
	cin>>m>>k;
	l=1;r=1000000000000000000;mid=(l+r)/2;
	while(l<=r)
	{
		mid=(l+r)/2;
		temp=solve(mid);
		if(temp==m)break;
		if(temp<m)l=mid+1;
		else r=mid-1;
	}
	cout<<mid<<"\n";
}