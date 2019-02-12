#include<iostream>
#include<algorithm>
#include<cmath>
#include<vector>
#include <stack>

#define IOS ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define lli long long int
using namespace std;
lli b[1000001][2][2]={};
int main()
{
	IOS
	lli n,i,tmp,a[1000001]={};lli ans=0;
	cin>>n;
	stack<int> indices_inc;
	stack<int> indices_dec;
	for(i=0;i<n;i++)
	{
		cin>>a[i];
		b[i][0][1]=b[i][1][1]=n;

		while(!indices_inc.empty() && a[indices_inc.top()]>a[i])
		{
			b[indices_inc.top()][0][1]=i;
			indices_inc.pop();
		}
		b[i][0][0]=(indices_inc.empty())?-1:(indices_inc.top());
		indices_inc.push(i);


		while(!indices_dec.empty() && a[indices_dec.top()]<a[i])
		{
			b[indices_dec.top()][1][1]=i;
			indices_dec.pop();
		}
		b[i][1][0]=(indices_dec.empty())?-1:(indices_dec.top());
		indices_dec.push(i);
	}
	
	for(i=0;i<n;i++)
		ans=ans+((1ll*a[i])*(-((b[i][0][1]-i)*(i-b[i][0][0]))+((b[i][1][1]-i)*(i-b[i][1][0]))));
	cout<<ans<<endl;	
}