#include <iostream>
#include <algorithm>
#define lli long long int
#define prime 1000000007 
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);  cout.tie(NULL);
	lli i,n,m,k,l=1,r,mid;
	cin>>n>>m>>k; r=n*m;
	while(l<=r)
	{

		mid=(l+r)>>1; lli temp=0;
		for(i=1;i<=n;i++)temp+=min((mid/i),m);
		if(temp>=k)r=mid-1;
		else l=mid+1;
		//cout<<mid<<" "<<temp<<endl;
	}
	cout<<l<<"\n";
}