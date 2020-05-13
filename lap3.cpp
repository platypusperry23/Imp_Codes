

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
	{	ll x,k;
		cin>>x>>k;
		if(x==1 && k==0)
			cout<<1<<endl;
		else
		{

		} 
 	} 
		return 0; 
}

    -> 1 2 3 5 6 10 15 30 


12 -> 1 2 3 4 6 12 
24 -> 1 2 3 4 6 8 12 24 
28 -> 1 2 7 4 14 28   
9  -> 1 3 9
4  -> 1 2 4 
5  -> 1 5 25
343-> 1 7 49 343 
 -> 1 5 25 125

   -> 1 2 3 6
36 -> 1 2 3 4 6 9 12 18 36
39 -> 1 3 13 39
3  -> 1 3 
42 -> 1 2 3 4 6 7 12 14 21 28 42  84
