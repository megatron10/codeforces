#include<iostream>
//#include<cmath>
//#include<string.h>
using namespace std;
int main()
{
	int n,t=0,ans=0;scanf("%d",&n);char a[n],c='0';scanf("%s",a);
	for(int i=0;i<n;i++)
	{
		if(a[i]!=c){ans+=t;c=a[i];t=0;}
		else t++;
	}
	ans+=t;
	printf("%d",ans);
	return 0;
}