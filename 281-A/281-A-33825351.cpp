#include<iostream>
#include<cmath>
#include<string.h>
using namespace std;
int main()
{
	char a[1000];
	cin>>a;
	a[0]=(a[0]%97%65)+65;
	printf("%s",a);
	return 0;
}