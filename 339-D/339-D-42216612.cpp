#include <iostream>
#include <algorithm>
#include <cmath>
#define lli long long int
#define prime 1000000007 
using namespace std;
lli tree[262144]={},n;
void merge(lli i)
{
	tree[i]=(((int)(n-(floor(log2(i)))))%2)?tree[i<<1]|tree[(i<<1)+1]:tree[i<<1]^tree[(i<<1)+1];
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);  cout.tie(NULL);
	lli i,m,p,b,temp;
	cin>>n>>m;temp=(1<<n);
	for(i=0;i<temp;i++) cin>>tree[temp+i];
	for(i=temp-1;i;i--) merge(i);
	while(m--)
	{
		cin>>p>>b;
		tree[i=temp+p-1]=b;
		while(i>>=1) merge(i);
		cout<<tree[1]<<"\n";
	}
}