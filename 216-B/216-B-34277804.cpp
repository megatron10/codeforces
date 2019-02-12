#include <iostream>
using namespace std;

	int k,l,a[100+1][2]={};
int length(int i,int ignore)
{
	int out=0;
	if(a[i][0]!=ignore && a[i][0])out++;
	if(a[i][1]!=ignore && a[i][1])out++;
	if(out==2) return(-1);	if(out==0) return(0);
	if(out==1) return( (a[i][0] && a[i][0]!=ignore)?a[i][0]:a[i][1]);
}
int main() 
{
	int n,m,cc; cin>>n>>m;
	bool b[n+1]={};
	for(int i=0;i<m;i++)
	{
		cin>>k>>l;
		a[k][0]?a[k][1]=l:a[k][0]=l;
		a[l][0]?a[l][1]=k:a[l][0]=k;
	}
	int nx=0;
	int noc=0,tmp1;
	for(int vr=1;vr<=n;vr++) 
	{	int i=vr;
		if(!b[i] && length(i,0)!=-1) 
		{	
				nx^=1;	tmp1=0; int in;
				while( (b[i]=1)&&length(i,tmp1) ) {in=i;i=length(i,tmp1);tmp1=in;nx^=1;}
		}
	}
	for(int vr=1;vr<=n;vr++) 
	{	int i=vr;
		if(!b[i]) 
		{	
			cc=1; tmp1=a[i][0];int tmp2=i;int in;
			while( (b[i]=1)&&length(i,tmp1)!=tmp2 ) {in=i;i=length(i,tmp1);tmp1=in;cc^=1;}
			nx+=cc;
		}
	}
	
	
	cout<<nx;
}