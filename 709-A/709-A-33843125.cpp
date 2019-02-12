#include<iostream>
//#include<cmath>
#include<string.h>
using namespace std;
int main()
{
	int n,b,d,k=0,ans=0,t;
	scanf("%d %d %d",&n,&b,&d);
	while(n--){scanf("%d",&t);if(t<=b){k+=t;if(k>d){k=0;ans++;}}}
	printf("%d",ans);
	return 0;
}