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
		 for(ll i=0;i<n;i++)
			{
				cin>>arr[i];
			}
			set<ll>s;
			um mp;
			ll g=0,eq=0;
		for(ll i=0;i<n/2;i++)
		{
			ll z=arr[i]+arr[n-i-1];
			s.insert(z);
			mp[z]+=1;
			if(z>k+1)
				g++;
			if(z==k+1)
				eq++;
		}
		n=n/2;
		ll min=(ll)1e8;
		for(auto i:s)
		{
			//cout<<i<<" "<<mp[i]<<" ";
			ll x=mp[i];
			if(i<(k+1))
			{
				ll pos=(n-x)+g;
				//cout<<pos<<endl;
				if(min>pos)
					min=pos;
			}
			else if(i>(k+1))
			{

				ll pos=n-x+(n-g-eq);
			//	cout<<pos<<endl;
				if(min>pos)
					min=pos;
			}

		}
		ll z=mp[k+1];
		
		ll pos=n-z;
		if(min>pos)
			min=pos;
		cout<<min<<endl;
	}

return 0; 
}


