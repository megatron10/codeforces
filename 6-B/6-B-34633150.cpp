#include <iostream>
#include<algorithm>
#include<string>
using namespace std;

struct {int a,b;} f[2]; 
int main()
{	
	bool k=0,ans[26]={}; int solved=0;
	f[1].a=f[1].b=-1;
	int m,n,j,i;char p; cin>>m>>n>>p;
	char c[m][n];
	for(i=0;i<m;i++) for(j=0;j<n;j++) {
		cin>>c[i][j];
		if(c[i][j]==p) {f[k].a=i;f[k].b=j;k=1;}
	}
	if(f[1].a==-1) f[1].a=f[0].a,f[1].b=f[0].b;
	if(f[0].a>0){for(i=f[0].b;i<=f[1].b;i++){if(c[f[0].a-1][i]!='.')ans[c[f[0].a-1][i]-'A']=1;}}
	if(f[1].a<m-1){for(i=f[0].b;i<=f[1].b;i++){if(c[f[1].a+1][i]!='.')ans[c[f[1].a+1][i]-'A']=1;}}
	
	if(f[0].b>0){for(i=f[0].a;i<=f[1].a;i++){if(c[i][f[0].b-1]!='.')ans[c[i][f[0].b-1]-'A']=1;}}
	if(f[1].b<n-1){for(i=f[0].a;i<=f[1].a;i++){if(c[i][f[1].b+1]!='.')ans[c[i][f[1].b+1]-'A']=1;}}
	for(i=0;i<26;i++) solved+=ans[i];
	cout<<solved;
}