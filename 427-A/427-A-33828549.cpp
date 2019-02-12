#include<iostream>
using namespace std;
int main() {
	
	int n,k,a=0,b=0; scanf("%d",&n);
	
	while(n--) {
		scanf("%d",&k);
		if(k!=-1) a+=k;
		else { 
			if(!a) { b++; } 
			else a--;
		}
	}
	cout<<b;
	
}