#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

#define lli long long int
#define del 0.000000001
using namespace std;

int main()
{
	// ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int i,j,n; double prob[101]={},ans=0,pro=1;
	cin>>n;
	for(i=0;i<n;i++)
		cin>>prob[i];
	sort(prob,prob+n,greater<double>()); i=0;
	while(i<n && (pro-ans)*prob[i]>del){
		ans=(ans*(1-prob[i]))+(pro*prob[i]);
		pro*=(1-prob[i++]);
	}
	printf("%.12lf",ans);	
	
}