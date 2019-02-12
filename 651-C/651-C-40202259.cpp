#include <iostream>
#include <algorithm>
#define lli long long int
using namespace std;
struct point {	lli x,y;  };
bool c1(point a,point b){return a.x<b.x||(a.x==b.x && a.y<b.y);}
bool c2(point a,point b){return a.y<b.y||(a.y==b.y && a.x<b.x);}
int main() 
{
  lli n,i,j,tmp,same,ans=0;cin>>n;
	point a[n];
	for(i=0;i<n;i++)cin>>a[i].x>>a[i].y;
	sort(a,a+n,c1);
	for(i=0;i<n;)
	{
		tmp=1;
		while(++i<n && a[i].x==a[i-1].x) tmp++;
		ans+=((tmp*(tmp-1))/2);
	}
	sort(a,a+n,c2);
	for(i=0;i<n;)
	{
		tmp=1;same=1;
		while(++i<n && a[i].y==a[i-1].y)
		{ 
			if(a[i-1].x==a[i].x)same++;
			else {ans-=((same*(same-1))/2); same=1;}
			tmp++;
		}
		ans+=((tmp*(tmp-1))/2)-((same*(same-1))/2);
	}
	cout<<ans;
}