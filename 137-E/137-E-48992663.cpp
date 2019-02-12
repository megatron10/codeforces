#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <utility>
#include <unordered_set>

#define ll long long int
#define INF 1000000
#define lim 100001
using namespace std;
struct node{
	int l,r,mim;
	void reset(int l=0,int r=0,int mim=INF)	{	this->mim=mim; this->l=l; this->r=r;}
};
vector<node> segTree(24*lim);
 
void merge(node& f,node j,node k)
{
	f.reset(j.l,k.r,min(j.mim,k.mim));
}
 
void merge(int i)
{
	merge(segTree[i],segTree[2*i],segTree[2*i+1]);
}
 
void build(int l,int r,int i=1)
{
	if(l==r) {segTree[i].reset(l,l,INF); return;}
	int m=(l+r)/2;
	build(l,m,2*i); build(m+1,r,2*i+1);
	merge(i);
}

void update_no(int l,int ind,int i=1)
{
	node &a=segTree[i];
	if(a.l==a.r && a.l==l){	 a.mim = min(a.mim,ind); return; }
	int mid = (a.l+a.r)/2;
	update_no(l,ind,2*i+(l>mid));
	merge(i);
}
 
int query(int val,int i=1)
{
	node &a=segTree[i];
	if(a.l>val) return INF;
	else if(a.r<=val) return a.mim;
	return min(query(val,2*i),query(val,2*i+1));
}

unordered_set<char> vowels({'a','e','i','o','u','A','E','I','O','U'});

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	build(1,6*lim);
	string s; cin>>s;
	int val = 2*(lim),i,l=0,nos=0,tmp;
	update_no(val,-1);
	for(i=0; i<s.length(); i++){
		if(vowels.count(s[i])) val--;
		else val += 2;
		update_no(val,i);
		tmp = i-query(val);
		if(tmp>l) { l = tmp; nos = 1; }
		else if(tmp==l) nos++;
	}
	if(l==0) cout<<"No solution";
	else cout<<l<<" "<<nos;
}