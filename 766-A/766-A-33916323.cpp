#include<iostream>
#include<algorithm>
//#include<cmath>
#include<string.h>
using namespace std;
int main()
{
	char a[100010],b[100010];
	scanf("%s",a);scanf("%s",b);
	if(!strcmp(a,b))printf("-1");
	else printf("%lu",max(strlen(a),strlen(b)));
	return 0;
}