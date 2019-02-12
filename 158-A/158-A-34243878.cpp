#include<iostream>
//#include<algorithm>
#include<cmath>
//#include<cstring>
using namespace std;
int main()
{	
	int n,i=0,t,t2,k;scanf("%d %d",&n,&k);
	for(i=0;i<k;i++)
	{
		scanf("%d",&t);
		if(!t)break;
	}
	if(i==k)
	{	
	t2=t;
	for(;i<n;i++)
	{
		scanf("%d",&t);
		if(t2!=t)break;
	}
	}
	printf("%d",i);
	return 0;
}