#include <iostream>
#include <algorithm>
#include <vector>
// #include <unordered_set>
#define lli long long int
using namespace std;
struct data
{
	lli val=0; int c=0;	
};
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int i,j,n,q;lli a,b;
	cin>>n>>q;
	

	int v[n+1],c[n+1]={}; lli temp[n+1]={},opt1,ans=0;
	
	for(i=1;i<=n;i++)cin>>v[i];
	for(i=1;i<=n;i++)cin>>c[i];
	
	for(i=0;i<q;i++)
	{
		cin>>a>>b;
		data best[2];best[1].val=-10000000001;
		ans=0;
		bool colors[n+1]={};
		// cout<<i<<"---\n";
		for(j=1;j<=n;j++)
		{			
			if(colors[c[j]])
				temp[c[j]]=max(temp[c[j]],opt1=max(temp[c[j]]+a*v[j],best[best[0].c==c[j]].val+b*v[j]));
			else
				temp[c[j]]=opt1=best[0].val+b*v[j],colors[c[j]]=1;
			
			ans=max(ans,opt1);
			
			if( opt1>=best[0].val ){
				if(c[j]==best[0].c){ best[0].val=opt1; continue; }
				swap(best[0],best[1]);
				best[0].val=opt1; best[0].c=c[j];
			}
			else if(opt1>best[1].val && c[j]!=best[0].c)
			{
				best[1].val=opt1; best[1].c=c[j];
			}			
		}
		cout<<ans<<endl;
	}
}