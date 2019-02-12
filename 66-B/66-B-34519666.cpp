#include<iostream>
using namespace std;
int main() 
{
	int n,i,maxm;cin>>n;int h[n],a[n]={},b[n+1]={};
	cin>>h[0];a[0]=0;b[n-1]=0;
	for(i=1;i<n;i++){cin>>h[i];a[i]=(h[i]>=h[i-1])?a[i-1]+1:0;}maxm=a[n-1];
	for(i=n-2;i>=0;i--){b[i]=(h[i]>=h[i+1])?b[i+1]+1:0;if(b[i]+a[i]>maxm)maxm=b[i]+a[i];}
	cout<<maxm+1;	
	return 0;
}