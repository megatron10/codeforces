#include <iostream>
#include <algorithm>
using namespace std;
int main() 
{
  string s;
	cin>>s;
	bool a[26]={};int oddc=0;
	for(int i=0;i<s.size();i++) oddc+=(a[s[i]-'a']^=1)?1:-1;
	if(oddc==0)oddc=1;
	cout<<((oddc%2)?"First":"Second");
}