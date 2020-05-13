
# include <bits/stdc++.h>
using namespace std;
#define boost     ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define ll        long long 
#define ld        long double
#define pi        3.14	
#define mkp       make_pair
#define pb     	  push_back	
#define pf     	  push_front
#define pob       pop_back
#define pof       pop_front
#define ins		  insert
#define mxy 	  map<pair<ll, ll>, ll>  
#define q1        1000000007
#define fl        forward_list
#define bin1      __builtin_popcount 
#define map2d	  map<long long,map<long long , long long > >
#define um		  unordered_map<ll,ll>
ll power(ll x, ll y) 
{
	ll p=q1;ll res = 1; x = x % p; 

	while (y > 0) {
	if (y & 1) 
		res = (res * x) % p; y = y >> 1;x = (x * x) % p; } return res; }

int main()
{
	boost;
	ll t,n;                    
	cin>>t;
	while(t--)
	{	
		cin>>n;
		
		ll arr[n];
		 for(ll i=0;i<n;i++)
		 cin>>arr[i];
		 ll max=0;
		 vector<ll> v;
		 for(ll i=0;i<n-1;i++)
		 {
		 	if(arr[i]>arr[i+1])
		 	{
		 		if(max < abs(arr[i]-arr[i+1]))
		 			max=abs(arr[i]-arr[i+1]);
		 		arr[i+1]=arr[i];		
		 	}
		 }
		 ll  x=0;
		 while(max>0)
		 {
		 	ll z=pow(2,x);
		 	max=max-z;
		 	x++;
		 }
		 cout<<x<<endl;
		
 	} 
		return 0; 
}


