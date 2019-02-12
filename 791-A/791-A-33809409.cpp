#include<iostream>
#include<cmath>
using namespace std;
int main()
{
	int a,b;
	scanf("%d %d",&a,&b);
	printf("%d",(int)(floor(log((double)(b)/a)/log(3.0/2))+1));
	return 0;	
}