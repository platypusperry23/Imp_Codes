#include <bits/stdc++.h>
using namespace   std;
#define boost     ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define ll        long long 
#define ld        long double
#define mkp       make_pair
#define pb         push_back  
#define pf         push_front
#define pob       pop_back
#define pof       pop_front
#define mxy     map<pair<ll, ll>, ll>  
#define q1        1000000007
#define bin1      __builtin_popcount 
#define map2d    map<long long,map<long long , long long > >
#define um      unordered_map<ll,ll>
#define INF       0x3f3f3f3f

int main()
{
  
  ll a,b;
    cin>>a>>b;
    
    ll m=(ll)max(a,b);
    ll m1=(ll)min(a,b);
    
    while((m%m1)!=0)
    {
      ll z=m%m1;
      m=m1;
      m1=z; 
    }
  cout<<m1<<endl;
    

return 0; 
}