#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
int main()
{
	int n,i=0;
	scanf("%d",&n);
	int a[n];
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	sort(a,a+n);
	for(i=0;i<n;i++)
	printf("%d ",a[i]);
}