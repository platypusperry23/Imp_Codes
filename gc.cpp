
# include <bits/stdc++.h>
using namespace std;
#define boost     ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define ll        long long 
#define ld        long double
#define pi        3.14  
#define mkp       make_pair
#define pb         push_back  
#define pf         push_front
#define pob       pop_back
#define pof       pop_front
#define ins      insert
#define mxy     map<pair<ll, ll>, ll>  
#define q1        1000000007
#define fl        forward_list
#define bin1      __builtin_popcount 
#define map2d    map<long long,map<long long , long long > >
#define um      unordered_map<ll,ll>

int main()
{
  boost;
  ll t,n;                    
  cin>>t;
  int z=1;
  while(t--)
  {  
    cin>>n;
    set<ll>s[n];
    ll row=0,col=0,trace=0;
     for(ll i=0;i<n;i++)
     {  
        um r;
        int flag=0;
        for(ll j=0;j<n;j++)
        {
            ll x;
            cin>>x;
             if(i==j)
             trace+=x; 
            if(r[x]==0)
            r[x]=1;
            else if(flag==0)
              flag=1;
            
            s[j].insert(x);
        }
        row+=flag;
     }
     for(int i=0;i<n;i++)
     {
      if(s[i].size()!=n)
        col++;
     }
    cout<<"Case #"<<z<<": "<<trace<<" "<<row<<" "<<col<<endl;
    z++;

   } 
    return 0; 
}


