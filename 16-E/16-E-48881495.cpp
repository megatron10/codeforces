#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
#define nfs ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ones __builtin_popcount
#define ll long long int
#define pr 1000000007
#define pb push_back
double dp[1<<18];
using namespace std;
int main()
{
	int n,i,j,cnt;
	double prob[18][18];
	cin>>n;
	for(i=0;i<n;i++) for(j=0;j<n;j++) cin>>prob[i][j];
	dp[i = (1<<n)-1] = 1.0;
	for(;i;i--)
	{
		cnt = ones(i); cnt = (cnt*(cnt-1))/2;
		vector<int> comp;
		for(j=0;j<n;j++) if(i&(1<<j)){
			for(auto k:comp){
				dp[i^(1<<j)] += (dp[i]/cnt)*prob[k][j];
				dp[i^(1<<k)] += (dp[i]/cnt)*prob[j][k];
			}
			comp.pb(j);
		}
	}
	for(i=0;i<n;i++) printf("%.6lf ",dp[1<<i]);
}