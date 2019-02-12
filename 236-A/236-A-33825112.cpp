#include<iostream>
#include<cmath>
#include<string.h>
using namespace std;
int main()
{
	char a[100];
	cin>>a;
	bool ar[26]={};
	int i=0,j=0;
	for(i=0;i<strlen(a);i++)ar[a[i]%97]=1;
	for(i=0;i<26;i++)if(ar[i])j++;
	if(j&1)printf("IGNORE HIM!");
	else printf("CHAT WITH HER!");	

	return 0;
}