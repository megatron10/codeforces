#include<iostream>
using namespace std;
int main()
{
	int n,tmp,t2=0,ans=0;
	cin>>n;
	bool a[n+1]={};
	n*=2;
	while(n--)
	{
		cin>>tmp;
		if(a[tmp])t2--;
		else {a[tmp]=1;if(++t2>ans)ans=t2;}
	}
	cout<<ans;
	return 0;
}