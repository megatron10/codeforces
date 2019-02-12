#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
int main() 
{
int t1=0,t2=0,i,n;
 cin>>n; n>>=1;
int a[n];
for(i=0;i<n;i++)cin>>a[i];
sort(a,a+n);
for(i=0;i<n;i++)
{ 
	t1=t1+(int)abs((i<<1)+1-a[i]);
	t2=t2+(int)abs((i<<1)+2-a[i]);
}
cout<<min(t1,t2);
return 0;
}