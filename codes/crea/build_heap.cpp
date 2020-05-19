#include <bits/stdc++.h>
using namespace   std;
#define boost     ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define ll        long long 
#define ld        long double
#define mkp       make_pair
#define pb            push_back
#define pf            push_front
#define pob       pop_back
#define pof       pop_froeant
#define ff        first
#define ss        second
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
  ll n;
  cin>>n;
  ll arr[n];
  vector<pair<int,int> >vi,ans;
  for(int i=0;i<n;i++)
  {
      cin>>arr[i];
        
        
  }
  for(int i=n-1;i>0;i--)
  {
      if(i%2==0)
      {
          int par=(i-2)/2;
          int cind=-1;
          if(arr[i]<arr[par] && arr[i]<arr[i-1])
          {
                cind=i;
          }
          else if(arr[i-1]<arr[par] && arr[i-1]<arr[i])
          {
              cind=i-1;
          }
            if(cind!=-1)
            {
                arr[par]=arr[cind];
                ans.pb(mkp(par,cind));
            }
            i--;
      }
      else
      {
          int par=i-1/2;
          if(arr[i]<arr[par])
          {
              ans.pb(mkp(par,i));
              arr[par]=arr[i];
          }
      }
  }
  cout<<ans.size()<<endl;
  for(auto i:ans)
  cout<<i.ff<<" "<<i.ss<<endl;

return 0; 
}


