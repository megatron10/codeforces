#include<iostream>
//#include<cmath>
//#include<string.h>
using namespace std;
int main()
{
	int ans=0,k,r,i=1,t;
	scanf("%d %d",&k,&r);
	while(1)
	{
		t=(k*i)%10;
		if(t==0 || t==r)break;
		i++;
	}
	printf("%d",i);
	return 0;
}