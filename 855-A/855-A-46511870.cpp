#include<iostream>
#include<algorithm>
#include <cmath>
#include <unordered_set>
#include <utility>
#define lli long long int
using namespace std;
unordered_set <string> past;

int main()
{
	int n;
	string s;
	cin>>n;
	while(n--){
		cin>>s;
		if(past.find(s)!=past.end())
			cout<<"YES\n";
		else{
			cout<<"NO\n";
			past.insert(s);
		}
	}
}