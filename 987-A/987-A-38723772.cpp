#include <iostream>
using namespace std;

int main() 
{
  int n,m;string s;
	string a[6]={"Power","Time","Space","Soul","Reality","Mind"};
	bool b[6]={};
	cin>>n;m=6-n;
	while(n--)
	{
		cin>>s;
		if(s[0]=='p')b[0]=true;
		else if(s[0]=='g')b[1]=true;
		else if(s[0]=='b')b[2]=true;
		else if(s[0]=='o')b[3]=true;
		else if(s[0]=='r')b[4]=true;
		else b[5]=true;
	}
	cout<<m<<"\n";
	for(int i=0;i<6;i++)	if(!b[i])cout<<a[i]<<"\n";
	 
}