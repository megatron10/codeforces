#include <iostream>
#include <cstring>
#include <algorithm>
#include <stack>
#include <unordered_set>
#define nfs ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long int
#define pr 1000000007
#define pb push_back
using namespace std;
int main()
{
	nfs;
	int i,n,t,c;
	stack<int> b;
	unordered_set<int> cl;
	cin>>n; int a[n+1];

	for(i=1;i<=n;i++)
		cin>>a[i];
	
	cin>>t;
	for(i=0;i<t;i++) { 
		cin>>c;
		cl.insert(c);
	}

	for(i=n; i; i--){
		if( cl.count(i) || b.empty() || b.top()!=a[i] )	b.push(-(a[i]=-a[i]));
		else b.pop();
	}
	if(!b.size()){
		cout<<"YES\n";
		for(i=1;i<=n;i++) cout<<a[i]<<" ";
	}
	else cout<<"NO";
}