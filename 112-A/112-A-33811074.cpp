#include<iostream>
#include<cmath>
#include<string.h>
using namespace std;
int main()
{
	int out=0,i=0;
	char a[100],b[100];
	cin>>a;cin>>b;
	while(i<strlen(a))
	{
		out=(a[i]%97%65)-(b[i]%97%65);
		if(out!=0)break;
		i+=1;
	}
	if(out)printf("%d",out/abs(out));
	else printf("0");
	return 0;
}