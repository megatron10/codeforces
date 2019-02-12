#include<iostream>
using namespace std;
int main()
{
	int n,i,an=0; 
	cin>>n;
	char a[n];
	cin>>a;
	for(i=0;i<n;i++){if(a[i]=='A'){an+=1;}}
	if(an>n/2.0)printf("Anton");
	else if(an==n/2.0)printf("Friendship");
	else printf("Danik");
	return 0;	
}