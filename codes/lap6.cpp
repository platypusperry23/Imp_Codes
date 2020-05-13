
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
	ll t,ques;                    
	cin>>t;
	while(t--)
	{	
		cin>>ques;
		ll ops;
		cin>>ops;
		ll sets;
		cin>>sets;
		map2d mp;
		ll arr[ques+1][ops+1];
		memset(arr,0,sizeof(arr));
		for(ll i=1;i<=ques;i++)
		{
			for(ll j=1;j<=sets;j++)
			{
				ll z;
				cin>>z;
				mp[i][j]=z;
				arr[i][z]+=1;

			}
		}
		
return 0; 
}


