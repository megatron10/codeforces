#include <iostream>
#include <algorithm>
#include <set>
#define lli long long int
#define prime 1000000007
using namespace std;
int main()
{
	int tmp1=0,tmp2=0,i,j,n,t,p[2*1000001]={}; cin>>n;
	set <int> a;
	for(i=0;i<n;i++){cin>>t; a.insert(t);}
	for(i=0;i<2*1000001;i++)p[i]=1000001;
	for(int v:a)p[v]=0;
	for(i=1;i<2*1000001;i++)if(p[i])p[i]=p[i-1]+1;
	for(int v:a)
		for(j=2*v;j<2*1000001;j+=v)
			tmp1=max(tmp1,(j-1-p[j-1]<v)?0:(v-((p[j-1]+1)%v))%v);
	cout<<tmp1;
}