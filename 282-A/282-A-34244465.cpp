#include<iostream>
using namespace std;
int main()
{	
	int n,i=0;cin>>n;
	string a;
	int k=0;
	for(k=0;k<n;k++)
	{
		cin>>a;
		if(a[1]=='+') ++i;
		else --i;
	}

	cout<<i;
}