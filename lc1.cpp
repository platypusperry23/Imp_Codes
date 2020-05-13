
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
  ll t,n,z=1;                    
  cin>>t;
  while(t--)
  {  
    cin>>n;
    
    vector< pair<ll,ll> > v,st;
    
    for(int i=0;i<n;i++)
    {
      int x,y;
      cin>>x>>y;
      st.pb(mkp(x,y));
      v.pb(mkp(x,y));
    }
    //cout<<v.size()<<endl; 
    sort(v.begin(),v.end());
    vector<ll>ans;
     int cend=0,jend=0,flag=0;

    for(int i=0;i<n;i++)
    { 
      int st=v[i].first;
      int en=v[i].second;
      if(i==0)
      {
        cend=en;
        ans.pb(0);
      }
      else 
      {
        if(cend <=st)
        {
          cend=en;
          ans.pb(0);
        }
        else if(jend <= st)
        {
          jend=en;
          ans.pb(1);
        }
        else
        {
          flag=1;
          break;
        }
      }
    }
    vector<ll> fan(n);
    map2d mp;
    int fl=0;
    for(int i=0;i<n;i++)
    {
      int x=v[i].first;
      int y=v[i].second;
      
      if(mp[x][y]==0)
        mp[x][y]=1;
      else
        fl=1;
      
      for(int j=0;j<n;j++)
        {
            int x1=st[j].first;
            int y1=st[j].second;
            if(x1==x && y1==y  && fl==0)
              {
                fan[j]=ans[i];
                break;
              }
            else if(x1==x && y1==y && fl==1)
              {
                fan[j]=ans[i];
                break;
              }
        }

      if(fl==1)
        fl=0;
    }
    if(flag==0){
      cout<<"Case #"<<z++<<": ";
      for(int i=0;i<fan.size();i++)
      {
        if(fan[i]==0)
          cout<<"C";
        else
          cout<<"J";
      }
      cout<<endl;
    }
    else
      cout<<"Case #"<<z++<<": IMPOSSIBLE"<<endl;
   } 
    return 0; 
}

