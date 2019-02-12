#include<iostream>
//#include<cmath>
#include<string.h>
using namespace std;
int main()
{
	int n,l; char in[100]; scanf("%d",&n);
	while(n--)
	{
		scanf("%s",in);l=strlen(in);
		l>10?printf("%c%d%c\n",in[0],l-2,in[l-1]):printf("%s\n",in);
	}
	return 0;
}