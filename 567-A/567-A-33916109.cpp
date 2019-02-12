#include<iostream>
#include<algorithm>
//#include<cmath>
//#include<string.h>
using namespace std;
int main()
{
	int n,t,i=0;scanf("%d",&n);
	int inp[n]={};
	for(i=0;i<n;i++)scanf("%d",&inp[i]);
	printf("%d %d\n",inp[1]-inp[0],inp[n-1]-inp[0]);
	for(i=1;i<n-1;i++)printf("%d %d\n",min(inp[i]-inp[i-1],inp[i+1]-inp[i]),max(inp[n-1]-inp[i],inp[i]-inp[0]));
	printf("%d %d",inp[n-1]-inp[n-2],inp[n-1]-inp[0]);	
	return 0;
}