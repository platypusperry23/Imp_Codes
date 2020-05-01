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

ll n,k,md=INF;
int  solve(ll arr[],ll index,ll sum)
{
      for(int i=index;i<n;i++)
      {
            if(sum+arr[i]>k)
            continue;
           
            sum=sum+arr[i];
            if(k-sum<md)
            md=k-sum;
            if(md==0)
            return 1;
            ll z;
            z= solve(arr,i+1,sum);
            if(z==1)
            return 1;
            sum=sum-arr[i];
            z=solve(arr,i+1,sum);
            if(z==1)
            return 1;
      }      
      return 0;
}
int main()
{
      
       cin>>k>>n;
       ll arr[n];
      for(ll i=0;i<n;i++)
              cin>>arr[i];
      sort(arr,arr+n);

   ll x=solve(arr,0,0);
   if(k-md>0)
      cout<<k-md<<endl;
      else
      {
            cout<<"0\n";
      }
      
return 0; 
}


