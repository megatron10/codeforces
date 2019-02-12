#include<iostream>
//#include<cmath>
#include<string.h>
using namespace std;
int main()
{
	int n,i,in;scanf("%d",&n);int inp[3][n],p[3]={0,0,0};	
	for(i=0;i<n;i++)
	{
		scanf("%d",&in);
		inp[in-1][p[in-1]]=i+1;
		p[in-1]++;		
	}
	in=p[0];
	if(p[1]<in)in=p[1];
	if(p[2]<in)in=p[2];
	printf("%d\n",in);
	for(i=0;i<in;i++)printf("%d %d %d\n",inp[0][i],inp[1][i],inp[2][i]);
	return 0;
}