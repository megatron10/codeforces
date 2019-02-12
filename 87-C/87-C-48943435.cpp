#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <set>
#include <cmath>
#define nfs ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long int
#define pr 1000000007
#define pb push_back
#define mp make_pair
#define lim 100001
using namespace std;
int pxor[lim],ans[lim];
vector<int> fact[lim];
int get_mex(set<int> &st)
{
	int mex = 0;
	while(st.find(mex)!=st.end()) mex++;
	return mex;
}
int main()
{
	int i,j,n;
	for(i=1;i<lim;i++)
		ans[i] = pr;//INF

	for(i=3;i<lim;i+=2)
		for(j=i;j<lim;j+=i)
			fact[j].pb(i);

	for(i=3;i<lim;i++)
	{
		set<int> st; int al,gr,f2=0;
		while(!(i&(1<<f2))) f2++;
		f2 = 1<<(f2+1);
		al = (i/f2) - ((f2-1)/2);
		if(al>0){
			st.insert(gr = pxor[al-1]^pxor[al+f2-1]);
			if(!gr) ans[i] = min(ans[i],f2);
		}
		for(auto f:fact[i]){
			al = (i/f) - ((f-1)/2);
			if(al<=0) break;
			st.insert(gr = pxor[al-1]^pxor[al+f-1]);
			if(!gr) ans[i] = min(ans[i],f);
			al = (i/(f2*f)) - (((f2*f)-1)/2);
			if(al>0){
				st.insert(gr = pxor[al-1]^pxor[al+(f2*f)-1]);
				if(!gr) ans[i] = min(ans[i],(f2*f));
			}
		}
		pxor[i] = pxor[i-1]^get_mex(st);
	}

	cin>>n;
	cout<<((ans[n]==pr)?-1:ans[n]);
}