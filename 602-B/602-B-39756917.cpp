#include <iostream>
#include <algorithm>
using namespace std;
int main() 
{
  int tmp=1,i,n,a[100001],z[100001][2];cin>>n;
	for(i=0;i<n;i++)cin>>a[i];
	z[0][0]=z[0][1]=1;
	for(i=1;i<n;i++)
	{
		if(a[i]==a[i-1])
		{
			z[i][0]=z[i-1][0]+1;
			z[i][1]=z[i-1][1]+1;
		}
		else if(a[i]>a[i-1])
		{
			z[i][1]=z[i-1][0]+1;
			z[i][0]=1;
		}
		else
		{
			z[i][0]=z[i-1][1]+1;
			z[i][1]=1;
		}
		tmp=max(tmp,max(z[i][0],z[i][1]));	
	}
	cout<<tmp;
}