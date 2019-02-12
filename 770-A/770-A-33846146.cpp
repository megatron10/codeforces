#include<iostream>
//#include<cmath>
//#include<string.h>
using namespace std;
int main()
{
	int n,j,i,k; scanf("%d %d",&n,&k);
	for(i=0;i<n;i++)putchar(97+(i%k));
	return 0;
}