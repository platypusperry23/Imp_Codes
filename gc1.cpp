
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
  int z=1;
  while(t--)
  {  
    string s;
    cin>>s;
    vector<ll> v;
    string w="\0";
    for(int i=0;i<s.length();i++)
    {
      int a=(int)s[i]-48;
        v.pb(a);
        if(i==0)
      {
        while(a>0)
        {
          w+="(";
          a--;
        }
        w+=s[i];
      }   
      else
      {
        if(v[i-1]<v[i])
        {
          int a=v[i-1];
          while(a>0)
          {
            w+=")";
            a--;
          }
          a=v[i];
          while(a>0)
          {
            w+="(";
            a--;
          }
          w+=s[i];
        }
        else if(v[i-1]>v[i])
        {
          int a=v[i-1]-v[i];
          while(a>0)
          {
            w+=")";
            a--;
          }
          w+=s[i];
        }
        else
          w+=s[i];
      }

    }
    int a=(int)s[s.length()-1]-48;
    while(a>0)
    {
      w+=")";
      a--;
    }
    cout<<"Case #"<<z<<": "<<w<<endl;
    z++;
   } 
    return 0; 
}


