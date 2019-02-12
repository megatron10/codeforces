#include <iostream>
#include <cmath>
#include <climits>
using namespace std;
int main() 
{
  int n,i,tmp,pos[1000001]={},state[1000001]={},tmp2,count=0;
	cin>>n;
	for(i=1;i<=n;i++)
	{
		cin>>tmp;
		pos[tmp]=i;
		state[i]=tmp;
	}
	for(i=1;i<=n;i++)
	{
		if(state[i]!=i)
		{
			count++;
			tmp=pos[i];
			tmp2=state[i];
			pos[i]=i;
			state[i]=i;
			state[tmp]=tmp2;
			pos[tmp2]=tmp;
			
		}
	}
	if(n%2==count%2)cout<<"Petr";
	else cout<<"Um_nik";
}