#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int main() 
{
  int counts[129]={},countt[129]={},yay=0,whoops=0,tmp;
	string s,t;
	cin>>s>>t;
	for(char i:s)counts[i]++;
	for(char i:t)countt[i]++;
	for(int i='A';i<='Z';i++)
	{
		tmp=min(counts[i],countt[i])+min(counts[i+32],countt[i+32]);
		whoops+=min(counts[i]+counts[i+32],countt[i]+countt[i+32])-tmp;
		yay+=tmp;
	}
	cout<<yay<<" "<<whoops;
}