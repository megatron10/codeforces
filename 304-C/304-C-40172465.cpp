#include <iostream>
#include <algorithm>
using namespace std;
int main() 
{
  int i,n;cin>>n;
	if(n&1)
	{
		for(i=0;i<n;i++)cout<<i<<" ";cout<<"\n";
		for(i=0;i<n;i++)cout<<i<<" ";cout<<"\n";
		for(i=0;i<n;i++)cout<<((2*i)%n)<<" ";cout<<"\n";
	}
	else cout<<"-1";
	return 0;
}