#include <iostream>
#include <algorithm>
#include <vector>
#define lli long long int
using namespace std;
int a[1048577]; lli part[25],part2[25],ans=0;
void merge(int l,int m,int r,int d)
{
	int i=l,j=m+1,k=0,tmp[r-l+1]={};
	while(i<=m && j<=r)
	{
		if(a[i]<=a[j]) tmp[k++] = a[i++];
		else { part[d] += m+1-i; tmp[k++] = a[j++]; }
	}
	if(i>m) while(j<=r) tmp[k++] = a[j++];
	else 	while(i<=m) tmp[k++] = a[i++];
	
	i=l; j=m+1; k=0;
	while(i<=m && j<=r)
	{
		if(a[j]>a[i]) { part2[d] += r+1-j; i++;}
		else j++;
	}
	
	for(i=l;i<=r;i++) a[i] = tmp[i-l];
}

void update(int q)
{
	for(int i=1;i<=q;i++){
		ans+=part2[i]-part[i];
		swap(part[i],part2[i]);
	}
}

void msort(int l,int r,int d)
{
	if(l==r)return;
	int m=(l+r)/2;
	msort(l,m,d-1);  msort(m+1,r,d-1);
	merge(l,m,r,d);
	// cout<<"\n-";
	// for(int i=l;i<=r;i++)cout<<a[i]<<" ";
	// cout<<endl;
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int i,n,m,q,lim;
	cin>>n; lim=1<<n;
	for(i=1;i<=lim;i++)
		cin>>a[i];

	msort(1,lim,n);

	for(i=1;i<=n;i++)
		ans+=part[i];

	cin>>m;
	// cout<<endl;
	// for(i=1;i<=n;i++)
	// 	cout<<i<<" "<<part[i]<<" "<<part2[i]<<endl;
	// cout<<"---"<<endl;
	
	for(i=0;i<m;i++){
		cin>>q;
		update(q);
		cout<<ans<<endl;
	}
}
/*
3
8 3 6 7 4 5 1 2
2
1 2
*/