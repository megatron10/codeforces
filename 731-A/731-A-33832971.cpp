#include<iostream>
//#include<cmath>
#include<string.h>
using namespace std;
int main()
{
	char in[100],c='a';
	scanf("%s",in);
	int i=0,l=strlen(in),t,ans=0;
	for(i=0;i<l;i++)
	{	
		t=abs(in[i]-c);
		ans+=(t>13?26-t:t);
		c=in[i];
	}
	printf("%d",ans);
	return 0;
}