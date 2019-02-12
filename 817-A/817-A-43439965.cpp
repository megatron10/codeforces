#include<bits/stdc++.h>
using namespace std;
int main()
{
	int x1,y1,x2,y2;
	cin>>x1>>y1>>x2>>y2;
	int x,y;
	cin>>x>>y;
	int xx1=abs(x2-x1);
	int yy1=abs(y2-y1);
	if(xx1%x==0 && yy1%y==0 )
		{
			xx1=xx1/x;
			yy1=yy1/y;
			if(xx1%2==yy1%2)
			cout<<"YES"<<endl;
			else
				cout<<"NO"<<endl;
		}
	else
		cout<<"NO"<<endl;
}