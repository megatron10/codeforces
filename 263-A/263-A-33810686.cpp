#include<iostream>
#include<cmath>
using namespace std;
int main()
{
	int count=0,t=0;
	while(!t)
	{
		scanf("%d",&t);
		count++;
	}
	printf("%d",abs(2-(count-1)/5)+abs((count-1)%5-2));
}