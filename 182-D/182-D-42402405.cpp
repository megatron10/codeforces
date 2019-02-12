#include <iostream>
#include <algorithm>
#define lli long long int
//#define p 1000000007
using namespace std;
int solve(string s)
{
	
	int t=-1,n=s.size(),p[s.size()+1]={};
	s="0"+s;
	p[0]=-1;
	for(int i=1;i<=n;i++)
	{
		if(t>=0 && s[i]!=s[t+1])t=p[t];
		p[i]=++t;
		//cout<<i<<" "<<t<<endl;
	}
	return (n%(n-p[n]))?n:(n-p[n]);
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);  cout.tie(NULL);
	string a,b; int i,count=0,tmp=0;
	cin>>a>>b;
	tmp=solve(a);
	if(a.substr(0,tmp)!=b.substr(0,solve(b)))goto done;
	for(i=tmp;i<=a.size();i+=tmp)
		if((a.size())%i==0 && (b.size())%i==0)
			count++;
	done:
	cout<<count<<"\n";
}