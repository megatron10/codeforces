#include <iostream>
#include<algorithm>
#include<iomanip>
using namespace std;
int main() {
	int n,l; cin>>n>>l; int a[n];
	for(int i=0;i<n;i++) cin>>a[i];
	sort(a,a+n);
	int m=max(a[0],l-a[n-1])<<1;
	for(int i=0;i<n-1;i++) 	if((a[i+1]-a[i])>m) m=(a[i+1]-a[i]);	
	printf("%0.10lf",m/2.0);
}