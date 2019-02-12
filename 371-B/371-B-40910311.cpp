#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
#define lli long long int
using namespace std;
int main()
{
	lli a,b;int c[6]={};memset(c,0,sizeof(c));
	cin>>a>>b;
	while(a%2==0){a/=2;c[0]++;}
	while(a%3==0){a/=3;c[1]++;}
	while(a%5==0){a/=5;c[2]++;}
	while(b%2==0){b/=2;c[3]++;}
	while(b%3==0){b/=3;c[4]++;}
	while(b%5==0){b/=5;c[5]++;}
	if(a==b)cout<<(abs(c[3]-c[0])+abs(c[4]-c[1])+abs(c[5]-c[2]))<<"\n";
	else cout<<"-1\n";
}