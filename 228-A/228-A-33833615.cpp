#include<iostream>
#include<unordered_set>
//#include<cmath>
//#include<string.h>
using namespace std;
int main()
{
	unordered_set <int>le;
	int t;
	//int ans=0,k,r,i=1,t;
	//scanf("%d %d",&k,&r);
	for(int i=1;i<=4;i++)
	{
		scanf("%d",&t);
		le.insert(t);
	}
	printf("%d",(int)(4-le.size()));
	return 0;
}