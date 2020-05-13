#include <bits/stdc++.h>
using namespace   std;
#define boost     ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define ll        long long 
#define ld        long double
#define mkp       make_pair
#define pb           push_back    
#define pf           push_front
#define pob       pop_back
#define pof       pop_front
#define mxy       map<pair<ll, ll>, ll>  
#define q1        1000000007
#define bin1      __builtin_popcount 
#define map2d      map<long long,map<long long , long long > >
#define um          unordered_map<ll,ll>
#define INF       0x3f3f3f3f


int main()
{
    boost;
    ll n;
    cin>>n;
    if(n<=1)
        cout<<n<<endl;
    else
    {
        ll a=0,b=1,sum=0;
        while(n-- >= 2)
        {
            sum=a+b;
            a=b;
            b=sum;
        }
        cout<<sum<<endl;
    }
return 0; 
}