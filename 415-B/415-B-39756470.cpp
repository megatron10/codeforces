#include <iostream>
#include <algorithm>
using namespace std;
int main() 
{
  long long int n,a,b,i;
	cin>>n>>a>>b;
	long long int inp;
	for(i=0;i<n;i++)
	{
		cin>>inp;
		cout<<((inp*a)%b)/a<<" ";
	}
}