#include<iostream>
#include<algorithm>
#include<utility>
#include<cmath>
#include <vector>
#include <map>
#define IOS ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;
vector<int> segTree[4000000];
vector<int> f(1000001);
void update(int i)
{
	int j=0,k=0;
	vector <int> &a=segTree[i],&b=segTree[2*i],&c=segTree[2*i+1]; 
	while(j<b.size() && k<c.size())
		a.push_back((b[j]<c[k])?b[j++]:c[k++]);
	while(k<c.size()) a.push_back(c[k++]);
	while(j<b.size()) a.push_back(b[j++]);
}

void build(int l,int r,int i)
{
	if(l==r) {segTree[i].push_back(f[l]);return;}
	int m=(l+r)/2;
	build(l,m,2*i); build(m+1,r,2*i+1);
	update(i);
}

int query(int val,int l,int r,int i,int lt,int rt)
{
	if(r<lt || l>rt)return 0;
	if(lt>=l && rt<=r)return (segTree[i].end()-upper_bound(segTree[i].begin(),segTree[i].end(),val));
	int mt=(lt+rt)/2;
	return query(val,l,r,2*i,lt,mt)+query(val,l,r,2*i+1,mt+1,rt);
}

int main()
{
	IOS
	int n,i,j,tmp;long long int ans=0; int a[1000001]={};
	cin>>n;
	map<int,int> count;
	for(i=1;i<=n;i++){
		cin>>a[i];
		if(count.find(a[i])==count.end()) count.insert(make_pair(a[i],1));
		else count[a[i]]++;
		f[i]=count[a[i]];
	} count.clear();
	build(1,n,1);

	for(j=n;j>1;j--){
		if(count.find(a[j])==count.end()) count.insert(make_pair(a[j],1));
		else count[a[j]]++;
		ans+=query(count[a[j]],1,j-1,1,1,n);
	}
	cout<<ans;


}