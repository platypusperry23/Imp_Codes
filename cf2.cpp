
# include <bits/stdc++.h>
using namespace std;
#define boost     ios_base::sync_with_stdio(false); cin.tie(NULL)
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
		ll n;
		cin>>n;
		ll arr[n];
		for(int i=0;i<n;i++)
		cin>>arr[i];

		ll pal[n][n];
		memset(pal,0,sizeof(pal));
		for(int i=0;i<n;i++)
			pal[i][i]=1;
		int fl=0,j=0;
		for(int cl=2;cl<=n;cl++)
		{
			for(int i=0;i<n-cl+1;i++)
				{ 
					j=i+cl-1;
					if(arr[i]==arr[j] && cl==2)
						pal[i][j]=2;
					else if(arr[i]==arr[j])
					pal[i][j]=pal[i+1][j-1]+2;
					else 
					pal[i][j]=max(pal[i+1][j],pal[i][j-1]);

				if(pal[i][j]>=3)
				{
					fl=1;
					break;
				}
			}
			if(fl==1)
				break;
		}
		
		if(fl==1)
			cout<<"YES\n";
		else
			cout<<"NO\n";

 	} 
		return 0; 
}


