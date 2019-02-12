#include<iostream>
#include<cmath>
//#include<string.h>
using namespace std;
int main()
{
	int n,t,d,k=0,ans=0	;
	scanf("%d %d %d %d",&n,&t,&k,&d);
	int l=(n-((k)*ceil((double)d/t)));
	if(l>0)
	{
		if(d%t==0){if(l-k>0)printf("YES");else printf("NO");}
		else printf("YES");
	}
	else printf("NO");
	return 0;
}