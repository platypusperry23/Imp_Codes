#include <bits/stdc++.h>
using namespace   std;
#define boost     ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define ll        long long 
#define ld        long double
#define mkp       make_pair
#define pb     	  push_back	
#define pf     	  push_front
#define pob       pop_back
#define pii 	  pair<ll,ll> 
#define pof       pop_front
#define mxy 	  map<pair<ll, ll>, ll>  
#define q1        1000000007
#define bin1      __builtin_popcount 
#define map2d	  map<long long,map<long long , long long > >
#define um		  unordered_map<ll,ll>
#define INF       0x3f3f3f3f
#define vec       vector<ll>

int main()
{
	
	ll n,m;
	cin>>n>>m;
	ll arr[m];
	priority_queue< pii,vector<pii >, greater < pii > > pq; 	
	for(int i=0;i<m;i++)
	{
		ll x;
		cin>>x;

		if(i<n)
		{
			pq.push(mkp(x,i));
			cout<<i<<" "<<0<<endl;
		}
		else
			arr[i]=x;
	}
	int i=n;
	while(i<m)
	{
		cout<<pq.top().second<<" "<<pq.top().first<<endl;
		ll z=pq.top().second;
		ll x=pq.top().first;
		pq.pop();
		if(i<m-1)
		{
			x=x+arr[i++];
			pq.push(mkp(x,z));
		}
		else
		{
			break;
		}
		

	}


return 0; 
}


