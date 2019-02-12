#include <iostream>
#include <algorithm>
using namespace std; 
int main() 
{
  int n,i,count[10]={};string s;
	cin>>n>>s;
	for(i=0;i<n;i++)count[s[i]-'0']++;
	count[3]+=count[4]+count[6]+(2*count[9]);
	count[2]+=(2*count[4])+(3*count[8])+count[9];
	count[5]+=count[6];
	count[7]+=count[8]+count[9];
	for(i=0;i<count[7];i++)cout<<"7";
	for(i=0;i<count[5];i++)cout<<"5";
	for(i=0;i<count[3];i++)cout<<"3";
	for(i=0;i<count[2];i++)cout<<"2";
}