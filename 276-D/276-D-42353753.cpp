#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
#include <unordered_set>

#define lli long long int
#define p 100000000
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);  cout.tie(NULL);
	lli l,r,ans;
	cin>>l>>r;
	ans=l^r;
	for(int i=0;i<=5;i++) ans|=ans>>(1<<i);
	cout<<ans;
	
}