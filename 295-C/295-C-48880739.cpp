#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
#define nfs ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long int
#define pr 1000000007
using namespace std;
struct state{ int n1,n2; bool d;};
int n1=0,n2=0; ll ans = 0;
int dp[51][51][2];
ll nways[51][51][2],fact[51],ifact[51],inv[51];
void pre()
{
	fact[0] = fact[1] = ifact[0] = ifact[1] = inv[1] = 1;
	for(int i = 2; i<51; i++){
		fact[i] = ( fact[i-1] * i )%pr;
		inv[i] = ( pr - ((inv[pr%i] * (pr/i))%pr) )%pr;
		ifact[i] = (ifact[i-1] * inv[i])%pr;
	}
}
ll ncr(int n,int r)
{
	return (n>=r)?((((fact[n]*ifact[r])%pr)*ifact[n-r])%pr):0;
}

int main()
{
        nfs;
	pre();
	int i,n,k,wt,j,steps; ll ways;
	cin>>n>>k; k /= 50;
	for(i=0; i<n; i++)
	{
		cin>>wt;
		(wt==50)?n1++:n2++;
	}
	memset(dp,-1,sizeof(dp));
	dp[n1][n2][1] = 0; nways[n1][n2][1] = 1;
	queue<state> bfs; bfs.push({n1,n2,1});
	while(!bfs.empty())
	{
		state u = bfs.front(),v; 
		state uc = u; bfs.pop();
		ways = nways[u.n1][u.n2][u.d];
		steps = dp[u.n1][u.n2][u.d];
		if(!u.d) {
			u.n1 = n1 - u.n1;
			u.n2 = n2 - u.n2;
		} 
		for(i=0; i<=u.n1; i++)
			for(j=(!i); (j*2 + i)<=k && j<=u.n2; j++){
				v = { uc.n1 + (u.d?-i:i), uc.n2 + (u.d?-j:j), !u.d };
				// cout<<" : "<<v.n1<<" "<<v.n2<<" "<<v.d<<" "<<dp[v.n1][v.n2][v.d]<<endl;
				if(dp[v.n1][v.n2][v.d] == -1){
					dp[v.n1][v.n2][v.d] = steps + 1;
					bfs.push(v);
				}
				if(dp[v.n1][v.n2][v.d] == steps + 1){
					ll &upd = nways[v.n1][v.n2][v.d];
					upd = (upd + (((ncr(u.n1,i)*ncr(u.n2,j))%pr)*ways)%pr)%pr; 
				}
		}
	}	
	cout<<dp[0][0][0]<<"\n"<<nways[0][0][0];
}