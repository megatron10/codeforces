#include<iostream>
//#include<algorithm>
//#include<cmath>
//#include<cstring>
using namespace std;
int main()
{	
	int n,i=0,j=0,t;cin>>n;int a[3]={};
	for(i=0;i<n;i++)
	{
		for(j=0;j<3;j++)
		{
			scanf("%d",&t);
			a[j]+=t;
		}
	}
	for(i=0;i<3;i++)if(a[i])break;
	if(i!=3)printf("NO");
	else printf("YES");
}