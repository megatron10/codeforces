#include<bits/stdc++.h>
using namespace std;
# define mx 100005
typedef int long long ll;
ll pre1[mx],pre2[mx],suff1[mx],suff2[mx],a[mx];
int main()
{
	ll n,p,q,r,final=LLONG_MIN,index1;
	cin>>n>>p>>q>>r;
	
	for(ll i=0;i<n;i++)
		cin>>a[i];		
	pre1[0]=a[0];
	pre2[0]=a[0];
	for(int i=1;i<n;i++)
	{
		pre1[i]=max(pre1[i-1],a[i]);
		pre2[i]=min(pre2[i-1],a[i]);		

	}
	suff1[n-1]=a[n-1];
	suff2[n-1]=a[n-1];
	for(int i=n-2;i>=0;i--)
	{
		suff1[i]=max(suff1[i+1],a[i]);
		suff2[i]=min(suff2[i+1],a[i]);	
	}
	if(p>=0 && q>=0 && r>=0)
	{
		final=pre1[n-1]*(p+q+r);
	}
	else if (p>=0 && q>=0 && r<0)
	{
		for(int i=0;i<n;i++)
		{
			final=max(final,(p+q)*pre1[i]+r*suff2[i]);
		}
	}
	else if(p>=0 && q<0 && r<0)
	{
		for(int i=0;i<n;i++)
		{
			final=max(final,(p)*pre1[i]+(r+q)*suff2[i]);
		}
	}
	else if(p<0 && q<0 && r<0)
	{
		
		final=pre2[n-1]*(p+q+r);
	}
	else if(p<0 && q<0 && r>=0)
	{		
		for(int i=0;i<n;i++)
		{
			final=max(final,(p+q)*pre2[i]+r*suff1[i]);
		}
	}
	else if(p<0 && q>=0 && r>=0)
	{		
		for(int i=0;i<n;i++)
		{
			final=max(final,(p)*pre2[i]+(q+r)*suff1[i]);
		}
	}
	else if(p<0 && q>=0 && r<0)
	{
		for(int i=0;i<n;i++)
		{
			final=max(final,p*pre2[i]+q*a[i]+r*suff2[i]);
		}
	}
	else if(p>=0 && q<0 && r>=0)
	{
		for(int i=0;i<n;i++)
		{
			final=max(final,p*pre1[i]+q*a[i]+r*suff1[i]);
		}
	}

	cout<<final<<endl;
}