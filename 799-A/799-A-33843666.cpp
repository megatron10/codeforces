#include<iostream>
#include<cmath>
//#include<string.h>
using namespace std;
int main()
{
	int n,t,d,k=0,ans=0	;
	scanf("%d %d %d %d",&n,&t,&k,&d);
	printf((d<(ceil((double)n/k)*t)-t)?"YES":"NO");
	return 0;
}