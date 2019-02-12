#include<iostream>
int main()
{
	int n,h,t,count=0;	
	scanf("%d %d",&n,&h);
	while(n--)
	{
		scanf("%d",&t);
		count+=t>h?2:1;
	}
	printf("%d",count);
	return 0;
}