#include <iostream>
#include <algorithm>
#include <cmath>
#define lli long long int
#define prime 1000000007 
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);  cout.tie(NULL);
	lli n;cin>>n;
	if(n%2){ cout<<"black"; }
	else{ cout<<"white\n1 2"; }
}