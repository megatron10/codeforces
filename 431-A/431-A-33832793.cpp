#include<iostream>
//#include<cmath>
#include<string.h>
using namespace std;
int main()
{
	int in[4],i=0,l,ans=0;
	char val[100000];
	scanf("%d %d %d %d",&in[0],&in[1],&in[2],&in[3]);
	scanf("%s",val);
	l=strlen(val);
	for(;i<l;i++)ans+=in[val[i]-'1'];	
	printf("%d",ans);
	return 0;
}