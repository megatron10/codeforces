#include<iostream>
#include<algorithm>
#include<utility>
#include<cmath>
#include<vector>
// #include<unordered_map>

#define IOS ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
// #define lli long long int
// #define p 1000000007
using namespace std;
struct node{
	int l,o,c;
	void reset()	{	this->l=this->o=this->c=0;	}
};

vector<node> segTree(4000001);
string f;

void merge(node& f,node j,node k)
{
	f.reset();
	f.l=(j.l+k.l+2*(min(j.o,k.c)));
	f.o=j.o+k.o-min(j.o,k.c);
	f.c=j.c+k.c-min(j.o,k.c);
}

void initialize(int i,int l)
{
	segTree[i].reset();
	(f[l]=='(')?segTree[i].o++:segTree[i].c++;
}

void build(int l,int r,int i)
{
	if(l==r) {initialize(i,l);return;}
	int m=(l+r)/2;
	build(l,m,2*i); build(m+1,r,2*i+1);
	merge(segTree[i],segTree[2*i],segTree[2*i+1]);
}

void take(int i){
	merge(segTree[0],segTree[0],segTree[i]);
}

void query(int l,int r,int i,int lt,int rt)
{
	if(r<lt || l>rt)return;
	if(lt>=l && rt<=r){ take(i); return; }
	int mt=(lt+rt)/2;
	query(l,r,2*i,lt,mt); query(l,r,2*i+1,mt+1,rt);
}
int act_query(int l,int r,int n)
{
	segTree[0].reset();
	query(l,r,1,1,n);
	return segTree[0].l;
}

int main()
{
	IOS
	cin>>f;
	f=" "+f;
	int i,n=f.size()-1,m,l,r;
	build(1,n,1);
	cin>>m;
	while(m--)
	{
		cin>>l>>r;
		cout<<act_query(l,r,n)<<endl;
	}
	//cout<<segTree[1].l<<" "<<segTree[1].o<<" "<<segTree[1].c<<endl;	
}