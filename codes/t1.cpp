
# include <bits/stdc++.h>
using namespace std;
#define boost     ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define ll        long long 
#define ld        long double
#define pi        3.14    
#define mkp       make_pair
#define pb           push_back    
#define pf           push_front
#define pob       pop_back
#define pof       pop_front
#define ins          insert
#define mxy       map<pair<ll, ll>, ll>  
#define q1        1000000007
#define fl        forward_list
#define bin1      __builtin_popcount 
#define map2d      map<long long,map<long long , long long > >
#define um          unordered_map<ll,ll>
ll power(ll x, ll y) 
{
    ll p=q1;ll res = 1; x = x % p; 

    while (y > 0) {
    if (y & 1) 
        res = (res * x) % p; y = y >> 1;x = (x * x) % p; } return res; }

int main()
{
    
    ll t,n;                    
    cin>>t;
    while(t--)
    { 
        cin>>n;
        if(n==1)
        cout<<"1\n";
        else
        cout << n/2 << "\n";
    if(n<=3)
    {
        if(n==1)
        cout<<1<<" "<<1<<"\n";
        else if(n==2)
        cout<<2<<" "<<1<<" "<< 2<<"\n";
        else if(n==3)
        cout<<3<<" "<<1<<" "<<2<<" "<<3<<"\n";
    }
    
    else    
        {
            cout<<3<<" "<<1<<" "<<2<<" "<<3<<endl;
            ll z=4; 
            while(z<=n)
            {
            if(n%2==0 && n==z)
                 cout<<1<<" ";
            else if(!(z&1))
                 cout << 2 << " ";
            cout << z <<" ";
            if(z&1)
                cout<<"\n";
            z++;
            }
            if(z%2==1)
            cout <<"\n";
        }   
    } 
        return 0; 
}

