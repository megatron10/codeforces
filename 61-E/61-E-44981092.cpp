#include<iostream>
#include<algorithm>
#include<utility>
#include<cmath>
#include<vector>
#include<unordered_map>

#define IOS ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define lli long long int
// #define p 1000000007
using namespace std;
vector<int> segTree[4000001];
vector<lli> f; int counts=0;

void merge(vector<int>& f,vector<int>& k,vector<int>& j)
{
	f.clear(); int a=0,b=0;
	while(a<j.size() && b<k.size())
		f.push_back((j[a]<k[b])?j[a++]:k[b++]);
	while(a<j.size()) f.push_back(j[a++]);
	while(b<k.size()) f.push_back(k[b++]);
}
void initialize(int i,int l)
{
	segTree[i].push_back(f[l]);
}

void build(int l,int r,int i)
{
	if(l==r) {initialize(i,l);return;}
	int m=(l+r)/2;
	build(l,m,2*i); build(m+1,r,2*i+1);
	merge(segTree[i],segTree[2*i],segTree[2*i+1]);
}

void take(int i,int val){
	counts+=segTree[i].end()-upper_bound(segTree[i].begin(),segTree[i].end(),val);
}

void query(int val,int l,int r,int i,int lt,int rt)
{
	if(r<lt || l>rt)return;
	if(lt>=l && rt<=r){ take(i,val); return; }
	int mt=(lt+rt)/2;
	query(val,l,r,2*i,lt,mt); query(val,l,r,2*i+1,mt+1,rt);
}
int act_query(int val,int l,int r,int n)
{
	// segTree[0].clear();
	// initialize(0,0);
	counts=0;
	query(val,l,r,1,1,n);
	return counts;
}

int main()
{
	IOS
	f.push_back(0);
	int i,n,t;int c1,c2;
	lli ans=0;
	cin>>n;
	for(i=0;i<n;i++){
		cin>>t;
		f.push_back(t);
	}
	unordered_map<int,int> countser;
	build(1,n,1);
	for(i=1;i<=n;i++)
	{
		if(countser.find(f[i])==countser.end())countser.insert(make_pair(f[i],1));
		else countser[f[i]]++;
		c1=((n-i+1)-countser[f[i]])-act_query(f[i],i,n,n);
		c2=act_query(f[i],1,i,n);
		ans+=((1ll*c1)*c2);
	}
	cout<<ans;	
}