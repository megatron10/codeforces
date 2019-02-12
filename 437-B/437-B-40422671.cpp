#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() 
{
	vector<int> answer;
  int sum,lim,i,j=0,k;
	cin>>sum>>lim;
	for(j=0;lim>>j;j++);
	while(--j>=0 && sum!=0)
	{
		i=min((lim>>(j+1))+(((1<<j)&lim)?1:0),sum/(1<<j));
		for(k=0;k<i;k++)answer.push_back((k<<(j+1))+(1<<j));
		sum-=i*(1<<j);
	}
	if(sum==0)
	{
		cout<<answer.size()<<"\n";
		for(auto ans:answer)cout<<ans<<" ";
	}
	else cout<<"-1";	
}