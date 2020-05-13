
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
#define hell      1000000007
#define fl        forward_list
#define rep(i,a,b)  for(ll i=a;i<b;i++)
#define bin1      __builtin_popcount 
#define map2d	  map<long long,map<long long , long long > >
#define um		  unordered_map<ll,ll>
ll power(ll x, ll y) 
{
	ll p=hell;ll res = 1; x = x % p; 

	while (y > 0) {
	if (y & 1) 
		res = (res * x) % p; y = y >> 1;x = (x * x) % p; } return res; }

int main()
{
	boost;
	ll t;cin>>t;	
	while(t--)
	{	
		ll n,k,x,y;
		cin>>n>>k>>x>>y;

		ll dp[n+2];
		dp[0]=1;dp[1]=0;
		rep(i,2,n+1)	
		{
			dp[i]=(dp[i-2]*(k-1))%hell +(dp[i-1]*(k-2))%hell;
			dp[i]%=hell;
			
			//test2(i,dp[i]);
		}
		if(x==y)
		cout<<dp[n-1]<<endl;
		else
		{
			//test1(dp[n]);
			ll lol=power(k-1,hell-2);
			ll ans=(dp[n]*lol)%hell;
			cout<<ans<<endl;
		}
	}
		return 0; 
}


