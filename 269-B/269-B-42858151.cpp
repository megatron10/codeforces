#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
	int n,m,inp[5001]={},ans[5001]={},j,i,temp=0;
	cin>>n>>m;float f;
	for(i=0;i<n;i++)
	{
		cin>>inp[i]>>f;
		ans[i]=1;
		for(j=0;j<i;j++) if(inp[j]<=inp[i]) ans[i]=max(ans[i],ans[j]+1);
		temp=max(temp,ans[i]);
	}
	cout<<n-temp;
}