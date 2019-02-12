#include<iostream>
using namespace std;
int main()
{	
	long long unsigned int n,k;cin>>n>>k;
	if(k>(((n>>1)+(n&1))))	cout<<(k-((n>>1)+(n&1))<<1);
	else cout<<(k<<1)-1;
	return 0;	
}