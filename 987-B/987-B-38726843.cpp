#include <iostream>
#include <cmath>
using namespace std;
int main() 
{
  long int x,y;
	cin>>x>>y;
	if((x==2 && y==4)||(x==4 && y==2)||(x==y)){cout<<"=";return 0;}
	if(x*log(y)>y*log(x))cout<<'<';
	else cout<<'>';
}