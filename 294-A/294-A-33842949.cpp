#include<iostream>
//#include<cmath>
#include<string.h>
using namespace std;
int main()
{
	int i=0,n,k,t1,t2;
	scanf("%d",&n); int a[n];
	for(i=0;i<n;i++)scanf("%d",&a[i]);
	scanf("%d",&k);
	while(k--)
	{
		scanf("%d %d",&t1,&t2);
		if(t1!=1 && t1!=n)
		{
			a[t1-2]+=t2-1;
			a[t1]+=a[t1-1]-t2;
			a[t1-1]=0;
		}
		else if(t1==1)
		{
			a[t1]+=a[t1-1]-t2;
			a[t1-1]=0;
		}
		else
		{
			a[t1-2]+=t2-1;
			a[t1-1]=0;
		}
	}
	for(i=0;i<n;i++)
	{
		printf("%d\n",a[i]);
	}

	return 0;
}