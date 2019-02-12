#include <iostream>
#include <string>
#include <cmath>
using namespace std;
int main() 
{
  int n,i=0,j=0,tmp;string s;
	cin>>n>>s;
	char a[n]={};
	tmp=(n%2)?-1:1; i=(n-1)/2;
	while(j<n)
	{
		a[i]=s[j++];
		i+=tmp;
		tmp=(abs(tmp)+1)*(-(tmp/abs(tmp)));
	}
	for(i=0;i<n;i++)cout<<a[i];
}