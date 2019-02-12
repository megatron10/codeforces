#include <iostream>
#include <algorithm>
#define lli long long int
//#define p 1000000007
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);  cout.tie(NULL);
	int x,y,z,xc,yc,zc,i,a[6]={};
	cin>>x>>y>>z>>xc>>yc>>zc;
	for(i=0;i<6;i++)cin>>a[i];
	cout<<((y<0)?a[0]:0)+((y>yc)?a[1]:0)+((z<0)?a[2]:0)+((z>zc)?a[3]:0)+((x<0)?a[4]:0)+((x>xc)?a[5]:0);
}