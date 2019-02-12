#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
struct req{int c,p,no;};
bool operator <(req a,req b) {return (a.p>b.p)||(a.p==b.p && a.c<b.c); }
int bs_gte(req *a,int v,int n)
{
	int l=0,r=n-1,mid;
	while(l<=r)
	{
		mid=(l+r)>>1;
		if(a[mid].p>=v)l=mid+1;
		else r=mid-1;
	}
	return r;
}
int main() 
{
	vector<req> output;
  int i,n,k,tmp=0,index,ans=0;
	cin>>n;
	req all[n];
	for(i=0;i<n;i++)all[i].no=i+1;
	for(i=0;i<n;i++)cin>>all[i].c>>all[i].p;
	cin>>k; req table[k]; bool alloted[k]={};
	for(i=0;i<k;i++)cin>>table[i].p;
	for(i=0;i<k;i++)table[i].c=table[i].no=i+1;
	sort(table,table+k);
	sort(all,all+n);
	for(i=0;i<n && tmp<k;i++)
	{
		index=bs_gte(table,all[i].c,k);
		for(;index>=0;index--)if(!alloted[index])break;
		if(index>=0)
		{
			tmp+=(alloted[index]=1);
			ans+=all[i].p;
			output.push_back({table[index].no,all[i].no});
		}
	}
	cout<<tmp<<" "<<ans<<"\n";
	for(auto out:output)	cout<<out.p<<" "<<out.c<<"\n";
}