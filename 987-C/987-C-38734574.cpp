#include <iostream>
#include <cmath>
#include <climits>
using namespace std;
int main() 
{
  long int ans=INT_MAX,i,j,n,s[3000]={},c[3000][3]={};
	cin>>n;
	for(i=0;i<n;i++)	cin>>s[i];
	for(i=0;i<n;i++)	cin>>c[i][0];
	for(i=1;i<n;i++)
	{
		for(j=0;j<i;j++)
		{
			if(s[j]<s[i])
			{
				if(c[i][1]!=0)c[i][1]=min(c[i][1],c[j][0]+c[i][0]);
				else c[i][1]=c[j][0]+c[i][0];

				if(c[j][1]!=0){if(c[i][2]!=0)c[i][2]=min(c[i][2],c[j][1]+c[i][0]);else c[i][2]=c[j][1]+c[i][0];}
			}
		}
	}
	for(i=0;i<n;i++)if(c[i][2]!=0)ans=min(ans,c[i][2]);
	if(ans==INT_MAX)cout<<"-1";
	else cout<<ans;
}