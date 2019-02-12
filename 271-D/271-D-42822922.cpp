#include <iostream>
#include <algorithm>
#include <unordered_set>
#define lli long long int
using namespace std;
int main()
{
	string s; lli hasher=0,z,k,i,j,pre[1511]={},ans=0; bool good[30]={};
	unordered_set <lli> sub;	
	cin>>s; char c;
	for(i=0;i<26;i++)	{cin>>c; good[i]=c-'0';} cin>>k;
	for(i=1;i<=s.length();i++)	pre[i]=pre[i-1]+((int)(!good[s[i-1]-'a']));
	i=0;j=0;
	for(i=0;i<s.length();i++)
	{

		while(j<s.length() && pre[j+1]-pre[i]<=k)j++;
		hasher=0;
		for(z=i;z<=j-1;z++)	{hasher=(hasher*29)+s[z]-'a'+1; sub.insert(hasher);}
	}
	cout<<sub.size();
}