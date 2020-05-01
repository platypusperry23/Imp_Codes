
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
	{	ll a,b;
		cin>>a>>b;
			int a4=a+b,a1=0,a2=0,a3=0;
			int x=a%10;//9
			int y=a/10;//0
			int x1=b%10;//2
			int y1=b/10;//4

			if( y && y1)
			 {
			 	a1=x*10+x1 + y*10+y1;
			 	a2=x*10+y1 + x1*10+y;
			 	a3=y1*10+y +x1*10+x;
			 }
			 else if(y==0 || y1==0)
			 {
			 	if(y1==0 && y==0)
			 	{
			 		a3=0;
			 		a4=0;
			 	}
			 	else if(y==0)
			 	{
			 		a1=y1*10+x+x1;
			 		a2=x*10+x1 + y1;
			 		
			 	}
			 	else if( y1==0)
			 	{
			 		a1=y*10+x1+x ;
			 		a2=x1*10+x+y;
			 	}
			 	
			 }

		int z= max(max(a1,a2),max(a4,a3));
		cout<<z<<endl;
		
		
		 
		 
		
 	} 
		return 0; 
}


