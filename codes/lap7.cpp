
# include <bits/stdc++.h>
using namespace std;
#define boost     ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define ll        unsigned long long 
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

vector<ll>v ;
void poN(ll n) 
{ 
	um mp;
	ll i=2;
	while(i<=(ll)(sqrt(n)))
	{   
	    if(mp[i]==1)
	    {
	        i++;
	        continue;
	    }
	    else
	    {
	        v.pb(i);    
	    }
	    for(ll j=i*i;j<=n;j=j*i)
	    {
	        mp[j]=1;
	    }
	    i++;
	}
	return;
} 
int main()
{
	boost;
	ll t,n;                    
	cin>>t;
    ll arr[t];
    ll max=0;
    for(ll i=0;i<t;i++)
    {
        cin>>arr[i];
        if(arr[i]>max);
       
        max=arr[i];
    }
    poN(max);
    for(int i=0;i<v.size();i++)
    {
    	cout<<v[i]<<" ";
    }
    cout<<endl;
	   for(int i=0;i<t;i++)
	   {
    	
    		ll ans=0,n=arr[i];
    		for(auto i:v)
    		{
    		    if(i*i<=n)
    		    {
    		        ll a=log(n)/log(i);
    		        if(a>=2)
    		        {
    		        ll b=pow(i,a);
    		        ll c=n%b;
    		        ll d=c/(i*i);
    		        ll e=((i*i)*d*(d-1))%q1;
    		        
    		   		 }
    		   		 else
    		   		 	break;
    		    }
    		}
    		cout<<endl;
    		cout<<ans+v[i]<<endl;
	   }
 	
		return 0; 
}


