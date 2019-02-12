#include<iostream>
//#include<cmath>
#include<string.h>
using namespace std;
int main()
{

	char in1[50],in2[50];
	scanf("%s",in1);
	scanf("%s",in2);
	int i,p=1;
	for(i=0;i<strlen(in2);i++)
	if(in1[p-1]==in2[i])p+=1;
	printf("%d",p);
	return 0;
}