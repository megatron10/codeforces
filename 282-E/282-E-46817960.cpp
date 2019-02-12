#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
#include <queue>
#define lli long long int
using namespace std;

struct node
{
	int t=0; node* c[2]={nullptr,nullptr};
	node(int v=0, node* l=nullptr,node* r=nullptr) { 	t=v; c[0]=l; c[1]=r;  }
}root;

void add(lli no)
{
	node* c=&root;
	for(auto i=39;i>=0;i--)
	{
		c->t++;
		node*& nxt=(c->c[((no>>i)&1)]);	if(!nxt) nxt=new node(1);
		c=nxt;
	}
}

lli query(lli no)
{
	node *c=&root; lli ret=(1LL<<40)-1,v=1LL<<39; bool k;
	for(int i=39,k=((no>>i)&1);i>=0;i--,v>>=1,k=(no>>i)&1)
		c=(c->c[!k])?(c->c[!k]):(ret^=v,c->c[k]);
	return ret;
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int i,n;
	cin>>n;
	lli a[n+1]={0},ans=0,xall;
	add(0);
	for(i=1;i<=n;i++){
		cin>>a[i];
		add(a[i]^=a[i-1]);
	}  	ans=xall=a[n];
	for(i=0;i<=n;i++)
		ans=max(ans,query(xall^a[i]));
	cout<<ans<<endl;
}