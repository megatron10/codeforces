#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
#define lli long long int
using namespace std;
int main()
{
	lli n,tmp=1;cin>>n;
	int i=2;
	for(;i<=sqrt(n);i++)
	{
		if(n%i==0)tmp*=i;
		while(n%i==0)n/=i;
	}
	tmp*=n;
	cout<<tmp<<"\n";
}