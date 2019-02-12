#include<iostream>
//#include<cmath>
//#include<string.h>
using namespace std;
int main()
{
	int ans=0,n,i=0,j=0;
	scanf("%d",&n);
	int h[n],a[n];
	for(i=0;i<n;i++)scanf("%d %d",&h[i],&a[i]);
	for(i=0;i<n;i++)for(j=0;j<n;j++){if(h[i]==a[j])ans++;}	
	printf("%d",ans);
	return 0;
}