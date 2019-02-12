#include <iostream>
#include <algorithm>
#define lli long long int
using namespace std;
int main()
{
	string s; lli go,i,count[2][2]={},ans[2]={};
	cin>>s;
	for(i=0;i<s.length();i++)
	{
		go=s[i]=='a'?0:1;
		count[go][i%2]++;
	}
	ans[0]=count[0][0]*count[0][1]+count[1][0]*count[1][1];
	ans[1]=((count[0][0]*(count[0][0]+1))/2)+((count[1][0]*(count[1][0]+1))/2)+((count[0][1]*(count[0][1]+1))/2)+((count[1][1]*(count[1][1]+1))/2);
	cout<<ans[0]<<" "<<ans[1];
}