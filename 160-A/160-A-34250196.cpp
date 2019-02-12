#include<iostream>
#include<algorithm>
#include<cmath>
//#include<cstring>
using namespace std;
int main()
{	
	int n,i=0,l=0,t=0;cin>>n;int a[n]={};
	for(;i<n;i++){scanf("%d",&a[i]);l+=a[i];}
	sort(a,a+n,greater<int>());//printf("\n%d\n",l);
	l=ceil(l/2.0)+(1-(l%2));//printf("\n%d\n",l);
	for(i=0;t<l;i++) t+=a[i];
	printf("%d",i);
}