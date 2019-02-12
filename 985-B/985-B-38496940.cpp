#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
int main() 
{
int n,m,i,j;
char c;
bool ok=false;
cin>>n>>m;
bool a[n][m];
int t[m]={};
for(i=0;i<n;i++) {for(j=0;j<m;j++){cin>>c; a[i][j]=c-'0'; t[j]+=a[i][j]?1:0;}}

for(i=0;i<n;i++) 
{
	for(j=0;j<m;j++) if(t[j]-(a[i][j]?1:0)<=0) break;
	if(j==m){ok=true; break;} 	
}
cout<<(ok?"YES":"NO");
return 0;
}