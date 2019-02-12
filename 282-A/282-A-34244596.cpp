#include<iostream>
using namespace std;
int main()
{	
	int n,i=0;	cin>>n;	char a[4];
	
	while(n--)
	{
		cin>>a;
		if(a[1]=='+') ++i;
		else --i;
	}

	cout<<i;
}