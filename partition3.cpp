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
bool var=false;
ll n;
vector<ll>v(3,0);
void solve(ll arr[], ll ind,ll cap)
{
      if(ind==n)
      var=true;
      for(int i=0;i<3;i++)
      {
            if(v[i]+arr[ind] > cap || var==true)
            continue;
            v[i]+=arr[ind];
            solve(arr,ind+1,cap);
            v[i]-=arr[ind];

            if(v[i]<=0)
            break;
      }
}
int main()
{
           
   cin>>n;
   ll arr[n];
   ll sum=0; 
   for(int i=0;i<n;i++)
   {
      cin>>arr[i];
      sum+=arr[i];
   }
   sort(arr,arr+n,greater<int>());
      if(sum%3!=0)
      {
            cout<<0<<endl;
            return 0;
      }
      else
      {
            ll z=sum/3;
            solve(arr,0,z);
            if(var==false)
            cout<<"0\n";
            else
            {
                  cout<<"1\n";
            }
            
      }
return 0; 
}


