#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
struct data{
	int l,u,n;
	data(){
		l=10000001; u=-1; n=0;
	}
};

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int i,j,n,m;
	cin>>n>>m;
	vector<int> x(m+1),y(m+1);
	data values[3*n+10][4];
	for(i=0;i<m;i++)
	{
		cin>>x[i]>>y[i];
		int up[4]={y[i]-x[i]+n,y[i]+x[i],y[i],x[i]};
		int cmp[4]={x[i],x[i],x[i],y[i]};
		for(j=0;j<4;j++){
			(values[up[j]][j]).n++;
			values[up[j]][j].l=min(values[up[j]][j].l,cmp[j]);
			values[up[j]][j].u=max(values[up[j]][j].u,cmp[j]);
		}
	}int counters[9]={},c;
	for(i=0;i<m;i++){
		c=0;
		int up[4]={y[i]-x[i]+n,y[i]+x[i],y[i],x[i]};
		int cmp[4]={x[i],x[i],x[i],y[i]};
		for(j=0;j<4;j++){
			data r=values[up[j]][j];
			if(r.n==1)continue;
			else if(r.n==2 || (r.n>2 && (cmp[j]==r.l || cmp[j]==r.u)))c++;
			else c+=2;
		}
		counters[c]++;
	}
	for(i=0;i<9;i++)
		cout<<counters[i]<<" ";
}