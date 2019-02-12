#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
#include <queue>
#define lli long long int
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int i,j,n,k,tmp;
	cin>>n>>k;
	int a[n];
	priority_queue <int> nos;
	
	unordered_map <int,int> counts; 
	for(i=0;i<k;i++)
	{
		cin>>a[i]; tmp=a[i];
		if(counts.find(tmp)!=counts.end()) counts[tmp]++; else counts.insert(make_pair(tmp,1)),nos.push(tmp);
	}
	
	while(!nos.empty() && counts[nos.top()]!=1 ) nos.pop();
	if(nos.empty()) cout<<"Nothing"; else cout<<nos.top();
	cout<<endl;
		
	for(;i<n;i++)
	{
		counts[a[i-k]]--;
		if(counts[a[i-k]]==1) nos.push(a[i-k]);
		cin>>a[i]; tmp=a[i];
		if(counts.find(tmp)!=counts.end()) counts[tmp]++;	else counts.insert(make_pair(tmp,1));
		if(counts[tmp]==1) nos.push(tmp);
		while(!nos.empty() && counts[nos.top()]!=1 ) nos.pop();
		if(nos.empty()) cout<<"Nothing"; else cout<<nos.top();
		cout<<endl;
	}

}