#include <iostream>
#include <algorithm>
#include <vector>
#define lli long long int
using namespace std;
int main()
{
	string s; cin>>s; s=' '+s;
	int tmp=0,t=0,i,p[s.length()+2]={};p[0]=-1; p[1]=0;
	for(i=2;i<s.length();i++)
	{
		tmp=max(tmp,t);
		while(t>=0 && s[i]!=s[t+1])t=p[t];
		p[i]=++t;
		//cout<<i<<" "<<t<<" "<<tmp<<endl;
	}
	vector<int> ans;
	while(t>=0){ans.push_back(t); t=p[t]; }ans.push_back(0);ans.push_back(0);
	reverse(ans.begin(),ans.end());
	int tmp2=upper_bound(ans.begin(), ans.end(), tmp)-ans.begin();
	tmp2=(ans[tmp2]==tmp)?ans[tmp2]:ans[tmp2-1];
	cout<<((tmp2)?s.substr(1,tmp2):"Just a legend");
}