#include<iostream>
//#include<cmath>
#include<string.h>
using namespace std;
int main()
{
	int i=0,ans=0,a,b;
	string out[]={"1/6","1/3","1/2","2/3","5/6","1/1"};
	scanf("%d %d",&a,&b);
	cout<<out[b>a?6-b:6-a];
	return 0;
}