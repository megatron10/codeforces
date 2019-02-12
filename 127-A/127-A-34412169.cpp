#include<iostream>
#include<cmath>
using namespace std;
int main()
{
	int n,k;
	int xo,yo,xn,yn;
	double ans=0.0;
	cin>>n>>k;n--;
	cin>>xo>>yo;
	while(n--)
	{
		cin>>xn>>yn;
		ans+=sqrt((xn-xo)*(xn-xo)+(yn-yo)*(yn-yo));
		yo=yn;xo=xn;
	}
	ans*=k;
	printf("%0.9f",ans/50);
	return 0;
}