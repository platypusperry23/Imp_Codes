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
vector<int> v[200007];
void ff(int n)
{
    map<int,int>mp;
   
    while(n%2==0){
        mp[2]++;
        n/=2;
    }
   
    for(int i=3;i<=sqrt(n);i+=2){
        while(n%i==0){
            mp[i]++;
            n/=i;
        }
    }
    if(n>1) 
    mp[n]++;

    for(auto p:mp) 
    	v[p.first].push_back(p.second);
}
int main()
{
	boost;
	int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        ff(x);
    }
	long long int ans=1;
    for(int i=2;i<200007;i++)
    {
        int x=v[i].size();
        
        if(x<n-1) 
        continue;
        sort(v[i].begin(),v[i].end());
        int yy=v[i][0];
        if(x==n) 
        yy=v[i][1];
        
        for(int j=0;j<yy;j++) 
        	ans*=i;
    }
  	  cout<<ans<<endl;	

return 0; 
}