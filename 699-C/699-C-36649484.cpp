#include <iostream>
#include<algorithm>
#include<climits>
using namespace std;
int main()
{
  int n,a,r=0,c=0,g=0,c_,ans=0;
  cin>>n;
  while(n--)
  {
    cin>>a;
    switch(a)
    {
      case 0: c=INT_MAX; g=INT_MAX; break;
      case 1: c=min(g,r); g=INT_MAX; break;
      case 2: g=min(c,r); c=INT_MAX; break;
      case 3: c_=c; c=min(g,r); g=min(c_,r); break;
    }
    r=ans+1;
    ans=min(min(r,c),g);
  }
  cout<<ans;
  return 0;
}