#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <set>
#include <cmath>
#include <utility>
#define nfs ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long int
#define pr 1000000007
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define lim 500001
using namespace std;
int main()
{
	int i,n; double ans=0.0,temp=0,psum=0.0,p;
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%lf",&p);
		psum += p;
		ans += temp = ((temp + 1)*p);
	}
	ans = 2*ans - psum;
	printf("%.6lf",ans);
}