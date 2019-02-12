#include <iostream>
#include <algorithm>
#include <vector>
#define lli long long int
using namespace std;
lli pre[1002][1002][4]={}; 
int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);    cout.tie(NULL);
   int n,m,i,j,k,inp[1001][1001]={};lli temp;
   cin>>n>>m;
   for(i=1;i<=n;i++) for(j=1;j<=m;j++) cin>>inp[i][j];
   for(i=1;i<=n;i++) for(j=1;j<=m;j++) pre[i][j][0]=max(pre[i-1][j][0],pre[i][j-1][0])+inp[i][j];
   for(i=n;i;i--) for(j=m;j;j--) pre[i][j][1]=max(pre[i][j+1][1],pre[i+1][j][1])+inp[i][j];
   for(i=1;i<=n;i++) for(j=m;j;j--) pre[i][j][2]=max(pre[i][j+1][2],pre[i-1][j][2])+inp[i][j];
   for(i=n;i;i--) for(j=1;j<=m;j++) pre[i][j][3]=max(pre[i][j-1][3],pre[i+1][j][3])+inp[i][j];
   for(i=2;i<n;i++)	  for(j=2;j<m;j++)
   temp=max({temp,pre[i][j-1][0]+pre[i][j+1][1]+pre[i-1][j][2]+pre[i+1][j][3],pre[i-1][j][0]+pre[i+1][j][1]+pre[i][j+1][2]+pre[i][j-1][3]});
	cout<<temp;
}