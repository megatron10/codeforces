#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <queue>
#define lli long long int
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int i,j,n,m,k,p,r=0,c=0;
	cin>>n>>m>>k>>p; lli inp[n+1][m+1],rpart[n+1]={},cpart[m+1]={},rsum[k+1]={},csum[k+1]={},ans=0;
	for(i=1;i<=n;i++)
		for(j=1;j<=m;j++)
		{
			cin>>inp[i][j];
			rpart[i]+=inp[i][j];
			cpart[j]+=inp[i][j];
		}

	priority_queue<lli> rows,cols;
	for(i=1;i<=n;i++) rows.push(rpart[i]);
	for(i=1;i<=m;i++) cols.push(cpart[i]);
	
	for(i=1;i<=k;i++)
	{
		lli tmp=rows.top();
		rsum[i]=rsum[i-1]+tmp;
		rows.pop(); rows.push(tmp-m*p);
	}

	for(i=1;i<=k;i++)
	{
		lli tmp=cols.top();
		csum[i]=csum[i-1]+tmp;
		cols.pop(); cols.push(tmp-n*p);
	}
	ans=csum[k];
	for(i=0;i<=k;i++)
		ans=max(rsum[i]+csum[k-i]-((1LL*(k-i)*i)*p),ans);
	cout<<ans<<endl;	
}