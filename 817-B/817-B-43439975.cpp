#include<iostream>
#include<algorithm>
#include<cmath>
#include<set>
#include<unordered_map>
#include<vector>
#define IOS ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define lli long long int
using namespace std;
int main()
{
	IOS
	int count=0,n,i,tmp,a[100001]={};lli ans;
	cin>>n;
	for(i=0;i<n;i++)cin>>a[i];
	sort(a,a+n);
	if(a[0]==a[2])
	{
		for(i=0;i<n;i++)if(a[i]==a[0])count++;
		ans=(1ll*count*(count-1)*(count-2))/6;
	}
	else if(a[1]==a[2])
	{
		for(i=1;i<n;i++)if(a[i]==a[1])count++;
		ans=(1ll*(count)*(count-1))/2;
	}
	else
	{
		for(i=2;i<n;i++)if(a[i]==a[2])count++;
		ans=count;
	}
	cout<<ans<<endl;	
}