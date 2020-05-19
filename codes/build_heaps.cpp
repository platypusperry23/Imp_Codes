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
#define ff		  first
#define ss 		  second
#define mxy 	  map<pair<ll, ll>, ll>  
#define q1        1000000007
#define bin1      __builtin_popcount 
#define map2d	  map<long long,map<long long , long long > >
#define um		  unordered_map<ll,ll>
#define INF       0x3f3f3f3f
#define vec       vector<ll>
vector<pair<int,int> > ans;
void heap(int arr[],int n,int i)
{	int cind=i;
	int par=arr[i];
	int c1=2*i+1;
	int c2=2*i+2;
	if(c1<n && arr[c1]<par)
	{
		par=arr[c1];
		cind=c1;
	}
  	if(c2<n && arr[c2]<par)
  	{
  		par=arr[c1];
  		cind=c2;
  	}
  	if(cind!=i)
  	{
  		ans.pb(mkp(i,cind));
  		swap(arr[i],arr[cind]);
  		heap(arr,n,cind);
  	}
  	
}
int main()
{
	int n;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++)
		cin>>arr[i];
	int s=n/2 -1;
	for(  ;s>=0;s--)
		heap(arr,n,s);
	cout<<ans.size()<<endl;
	for(auto i:ans)
		cout<<i.ff<<" "<<i.ss<<endl;


return 0; 
}


