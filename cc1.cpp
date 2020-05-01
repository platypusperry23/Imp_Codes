#include <bits/stdc++.h>
using namespace   std;
#define boost     ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define ll        long long 
#define ld        long double
#define mkp       make_pair
#define pb            push_back
#define pf            push_front
#define pob       pop_back
#define pof       pop_front
#define mxy       map<pair<ll, ll>, ll>  
#define q1        1000000007
#define bin1      __builtin_popcount 
#define map2d      map<long long,map<long long , long long > >
#define um         unordered_map<ll,ll>
#define INF       0x3f3f3f3f
ll power(ll x, ll y) 
{
   ll p=q1;ll res = 1; x = x % p; 

   while (y > 0) {
   if (y & 1) 
    res = (res * x) % p; y = y >> 1;x = (x * x) % p; } return res; }

int main()
{
 
   ll t,n;                    
   cin>>t;
   while(t--)
   {   
       cin>>n;
       
       ll arr[n];
      for(ll i=0;i<n;i++)
              cin>>arr[i];
    }

return 0; 
}


