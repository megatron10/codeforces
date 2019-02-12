#include<iostream>
#include<cmath>
using namespace std;
int main()
{
	int n,ans=0,a[3];
	scanf("%d",&n);
	while(n--)
		{
			scanf("%d",&a[0]);scanf("%d",&a[1]);scanf("%d",&a[2]);
			if(a[0]+a[1]+a[2]>=2)ans+=1;
		}
	printf("%d",ans);	
	return 0;	
}