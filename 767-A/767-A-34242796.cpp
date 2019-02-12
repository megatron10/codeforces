#include<iostream>
//#include<algorithm>
#include<cmath>
//#include<cstring>
using namespace std;
int main()
{	
	int  n,i,t;  scanf("%d",&n);bool a[n]={};int j=n;
	for(i=1;i<=n;i++)
	{
		scanf("%d",&t);
		a[t-1]=1;
		while(j>0 && a[j-1])printf("%d ",j--);
		printf("\n");
	}
	return 0;
}