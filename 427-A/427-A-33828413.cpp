#include<iostream>
//#include<cmath>
//#include<string.h>
using namespace std;
int main()
{
	int n,in,free=0,ans=0;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%d",&in);
		if(in!=-1)free+=in;
		else{if(!free)ans++; else free--;}
	}
	printf("%d",ans);
	return 0;
}