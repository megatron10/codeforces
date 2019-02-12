//https://codeforces.com/problemset/problem/242/E
#include<iostream>
#include<algorithm>
#include<utility>
#include<cmath>
#include<vector>

#define IOS ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define lli long long int
using namespace std;
struct node{//problem based
	lli l,r,n,lazy; int counts[20]={};
	void reset(int* tmp,lli l=0,lli r=0)	{this->lazy=0; for(int i=0;i<20;i++)this->counts[i]=tmp[i]; this->l=l; this->r=r; this->n=r-l+1; }
};

vector<lli> arr(100001);
vector<node> segTree(400001);

void merge(node& f,node& j,node& k)//problem based
{
	int tmp[20]={};
	for(int i=0;i<20;i++)
		tmp[i]=((j.lazy&(1<<i))?(j.n-j.counts[i]):j.counts[i])+((k.lazy&(1<<i))?(k.n-k.counts[i]):k.counts[i]);
	f.reset(tmp,j.l,k.r);
}

void merge(int i)
{
	merge(segTree[i],segTree[2*i],segTree[2*i+1]);
}

//problem based
void init(node& i,int index)
{
	int tmp[20];
	for(int i=0;i<20;i++)
		tmp[i]=(arr[index]>>i)&1;
	i.reset(tmp,index,index);
}

void build(int l,int r,int i=1)
{
	if(l==r) {init(segTree[i],l); return;}
	int m=(l+r)/2;
	build(l,m,2*i); build(m+1,r,2*i+1);
	merge(i);
}

inline void take(int i){	merge(segTree[0],segTree[0],segTree[i]); }

//problem based
inline void update_lazy(lli val,node &d)
{
	d.lazy^=val;
}

//problem based
inline void update_lazy(node &a,node &b) { 	update_lazy(a.lazy,b); }

//problem based
inline bool check_lazy(node &a){ return a.lazy; }

void push(int i)
{
	update_lazy(segTree[i],segTree[2*i]);
	update_lazy(segTree[i],segTree[2*i+1]);
	merge(i);
}

//minorly problem based
void range_update(lli val,int l,int r,int i=1)
{
	node &a=segTree[i];
	if(r<a.l || l>a.r)return;
	if(a.l>=l && a.r<=r){ update_lazy(val,a); return; }
	if(check_lazy(a)) push(i);
	range_update(val,l,r,2*i); range_update(val,l,r,2*i+1);
	merge(i);
}

/*
void update_no(int l,int i=1)
{
	node &a=segTree[i];
	if(a.l==a.r){ init(a,l); return; }
	update_no(l,2*i+(l>(a.l+a.r)/2));
	merge(i);
}*/

void query(int l,int r,int i=1)
{
	node &a=segTree[i];
	if(r<a.l || l>a.r)return;
	if(a.l>=l && a.r<=r){ take(i); return; }
	if(check_lazy(a)) push(i);
	query(l,r,2*i); query(l,r,2*i+1);
}

//problem based
lli act_query(int l,int r)
{
	int tmp[20]={};
	segTree[0].reset(tmp,0,0);
	query(l,r);
	lli ans=0;
	for(int i=0;i<20;i++)
		ans+=(segTree[0].counts[i])*(1LL<<i);
	return ans;
}

int main()
{
	IOS
	lli i,j,n,m,k,d,l,r,x;
	cin>>n;
	for(i=1;i<=n;i++)
		cin>>arr[i];
	build(1,n);
	cin>>m;
	while(m--){
		cin>>d>>l>>r;
		if(d==2){
			cin>>x;
			range_update(x,l,r);
		}
		else
			cout<<(act_query(l,r))<<endl;
	}
}