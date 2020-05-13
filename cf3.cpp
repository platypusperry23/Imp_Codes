
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
	cin>>n;
	if (n%2==0)
		cout<<"NO\n";
	else
		{cout<<"YES\n";
	ll c=1,i=1,z=0;
	vector<ll>v1(2*n+1,0);
	while(i<=2*n)
	{
		if(z==0)
		{
			v1[c]=i;
			v1[c+n]=i+1;
			i=i+2;
			z=1;
			c++;
		}
		else
		{
			v1[c]=i+1;
			v1[c+n]=i;
			z=0;
			i=i+2;
			c++;
		}
	}
	for(int i=1;i<v1.size();i++)
		cout<<v1[i]<<" ";
	cout<<endl;
	}
return 0; 
}


