#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <set>
#include <cmath>
#include <utility>
#define nfs ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long int
#define pr 1000000007
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define lim 100001
using namespace std;
int main()
{
	int i,n,q=0,z=0,o=0,free;char a[lim]; bool isp[4],lisp[4];
	string s; cin>>s; n=s.length();
	for(i=0;i<n;i++){
		a[i]=s[i];
		switch(a[i])
		{
			case '?': q++; break;
			case '0': z++; break;
			case '1': o++;
		}
	}
	if(o+q-z>=2) isp[3]=1;
	if(z+q-o>=1) isp[0]=1;
	if(!(n&1) && abs(z-o)<=q){
		free = (q-abs(z-o))/2;
		if(a[n-1]!='?' || free==0){
			int c=(z>o)?1:0;
			if(a[n-1]!='?') c = a[n-1] - '0';
			isp[c+2*(1-c)]=1;
		}
		else
			isp[1]=isp[2]=1;
	}
	if( n&1 && abs(o-z-1)<=q )
	{
		if(a[n-1]=='?'){
			if(abs(o-z)<=q-1) isp[1]=1;
			if(abs(o-z-2)<=q-1) isp[2]=1;	
		}
		else {
			int c=a[n-1]-'0';
			isp[c+2*(1-c)]=1;
		}
	}
	if(isp[0]) cout<<"00\n";
	if(isp[1]) cout<<"01\n";
	if(isp[2]) cout<<"10\n";
	if(isp[3]) cout<<"11\n";
}