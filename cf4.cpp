#include <bits/stdc++.h>
using namespace   std;
#define boost     ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define ll        long long 
#define ld        long double
#define mkp       make_pair
#define pb     	  push_back	
#define pf     	  push_front
#define pob       pop_back
#define pof       pop_front
#define mxy 	  map<pair<ll, ll>, ll>  
#define q1        1000000007
#define bin1      __builtin_popcount 
#define map2d	  map<long long,map<long long , long long > >
#define um		  unordered_map<ll,ll>
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
		ll k;
		cin>>n>>k;
		ll arr[n];
		ll fre[2*k+2]={0};
		for(ll i=0;i<n;i++)
		cin>>arr[i];
		um mp;
		for(ll i=0;i<n/2;i++)
		{
			ll sum=arr[i]+arr[n-i-1];
			mp[sum]+=1;
			fre[(min(arr[i],arr[n-i-1])+1)]+=1;
			fre[(max(arr[i],arr[n-i-1])+k+1)]-=1;
		}
		n=n/2;
		ll m=(ll)1e8;
		for(ll i=2;i<=2*k;i++)
		{
			fre[i]=fre[i-1]+fre[i];
		//	cout<<fre[i]<<" ";

			ll x=n-mp[i]+(n-fre[i]);
			if(x<m)
				m=x;
		}
		//cout<<endl<<endl;
		cout<<m<<endl;
	}

return 0; 
}


