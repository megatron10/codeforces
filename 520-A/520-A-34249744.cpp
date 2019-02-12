#include<iostream>
//#include<algorithm>
//#include<cmath>
//#include<cstring>
using namespace std;
int main()
{	
	int n,c=0; cin>>n; bool a[26]={};
	char t;
	while(n--) {
		cin>>t;
		if(!a[(t%97)%65]) {
			c++;
			a[(t%97)%65]=1;
		}
	}
	if(c==26) cout<<"YES";
	else cout<<"NO";
}