#include<iostream>
//#include<cmath>
//#include<string.h>
using namespace std;
int main()
{
	int n,t,i=0;scanf("%d",&n);
	int ans[n]={};
	for(i=1;i<=n;i++)
	{
		scanf("%d",&t);
		ans[t-1]=i;
	}
	for(i=0;i<n;i++)printf("%d ",ans[i]);
	return 0;
}