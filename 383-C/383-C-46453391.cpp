#include <iostream>
#include <algorithm>
#include <utility>
#include <cmath>
#include <vector>

#define IOS ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define lli long long int
using namespace std;
struct node{//problem based
	lli l,r,n,lazy,sum;
	void reset(lli val=0,lli l=0,lli r=0)	{ this->sum=val; this->lazy=0; this->l=l; this->r=r; this->n=r-l+1; }
};
struct vertex{
	int s[2],e[2]; bool k;
	vertex(){
		s[0]=s[1]=s[0]=s[2]=-1; k=0;
	}
};
int counter[2]={};
vector<vertex> v(200001);
vector<node> segTree[2];
lli a[200001]={};
vector<int> graph[200001];
void merge(node& f,node& j,node& k)//problem based
{
	f.reset((j.n)*j.lazy+(k.n)*k.lazy+j.sum+k.sum,j.l,k.r);
}

void merge(int i,bool w)
{
	merge(segTree[w][i],segTree[w][2*i],segTree[w][2*i+1]);
}

//problem based
void init(node& i,int index)
{
	i.reset(0,index,index);
}

void build(int l,int r,bool w=0,int i=1)
{
	if(l==r) {init(segTree[w][i],l); return;}
	int m=(l+r)/2;
	build(l,m,w,2*i); build(m+1,r,w,2*i+1);
	merge(i,w);
}

inline void take(int i,bool w){ merge(segTree[w][0],segTree[w][0],segTree[w][i]); }

//problem based
inline void update_lazy(lli val,node &d)
{
	d.lazy+=val;
}

inline void update_lazy(node &a,node &b) { 	update_lazy(a.lazy,b); }

//problem based
inline bool check_lazy(node &a){ return a.lazy; }

void push(int i,bool w)
{
	update_lazy(segTree[w][i],segTree[w][2*i]);
	update_lazy(segTree[w][i],segTree[w][2*i+1]);
	merge(i,w);
}

//minorly problem based
void range_update(lli val,int l,int r,bool w,int i=1)
{
	node &a=segTree[w][i];
	if(r<a.l || l>a.r)return;
	if(a.l>=l && a.r<=r){ update_lazy(val,a); return; }
	if(check_lazy(a)) push(i,w);
	range_update(val,l,r,w,2*i); range_update(val,l,r,w,2*i+1);
	merge(i,w);
}

void query(int l,int r,bool w,int i=1)
{
	node &a=segTree[w][i];
	if(r<a.l || l>a.r)return;
	if(a.l>=l && a.r<=r){ take(i,w); return; }
	if(check_lazy(a)) push(i,w);
	query(l,r,w,2*i); query(l,r,w,2*i+1);
}

lli act_query(int l,int r,bool w)
{
	if(r<l)return 0;
	segTree[w][0].reset(0,0,0);
	query(l,r,w);
	return segTree[w][0].sum;
}

void dfs(int u,int pa,bool type){
	v[u].k=type;
	v[u].s[0]=counter[0]; v[u].s[1]=counter[1];
	counter[type]++;
	for(int next:graph[u])
		if(next!=pa)
			dfs(next,u,!type);
	v[u].e[0]=counter[0]; v[u].e[1]=counter[1];
}

int main()
{
	IOS;
	segTree[0].reserve(1<<19); segTree[1].reserve(1<<19);
	int i,j,u,ve,d,x,val,n,m;
	cin>>n>>m;
	for(i=1;i<=n;i++)
		cin>>a[i];
	
	for(i=1;i<n;i++){
		cin>>u>>ve;
		graph[u].push_back(ve);
		graph[ve].push_back(u);
	}

	dfs(1,0,0);

	build(0,counter[0],0);
	build(0,counter[1],1);

	while(m--){
		cin>>d>>x;
		bool type=v[x].k;
		if(d==1){
			cin>>val;
			range_update(val,v[x].s[type],v[x].e[type]-1,type);
			if(v[x].e[!type]!=v[x].s[!type]) range_update(-val,v[x].s[!type],v[x].e[!type]-1,!type);
		}
		else
			cout<<(act_query(v[x].s[type],v[x].s[type],type)+a[x])<<endl;
	}
}