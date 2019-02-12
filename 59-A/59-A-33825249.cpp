#include<iostream>
#include<cmath>
#include<string.h>
using namespace std;
int main()
{
	char a[100];
	cin>>a;
	int i=0,hi=0,l=strlen(a);
	for(;i<l;i++)
	{
		if(a[i]>='A' && a[i]<='Z'){a[i]+=32;hi+=1;}
	}
	if(hi>l-hi){for(i=0;i<l;i++)a[i]-=32;}
	printf("%s",a);
}