#include<iostream>
//#include<cmath>
//#include<string.h>
using namespace std;
int main()
{
	int n,i,l=0,u,p1=0,p2=0,t;
	scanf("%d",&n);u=n-1;
	int a[n];
	for(i=0;i<n;i++)scanf("%d",&a[i]);
	for(i=1;i<=n;i++)
	{
		if(a[u]>a[l])t=a[u--];
		else t=a[l++];
		if(i&1)p1+=t;
		else p2+=t;
	}
	printf("%d %d",p1,p2);	
	return 0;
}