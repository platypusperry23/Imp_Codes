
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
#define um      unordered_map<ll,bool>
  
vector<ll> s1;
um vis;
vector<vector<int> > ssc(100000,vector<int>());

void dfs(vector<vector<int> > &adj,int a)
{
  if(vis[a]==false)
  {
     vis[a]=true;
     for(int i=0;i<adj[a].size();i++)
      {
        if(vis[adj[a][i]]==false)
        {
          dfs(adj,adj[a][i]);
          
          
        }
      }
     s1.pb(a);
    
  }
  return;
  
}
void rdfs(vector<vector<int> > adj,int a,int z)
{
  if(vis[a]==false)
  {
     vis[a]=true;
     ssc[z].pb(a);
     for(int i=0;i<adj[a].size();i++)
      { 
        if(vis[adj[a][i]]==false)
        {
          rdfs(adj,adj[a][i],z );
        }
      }
  }
  return;
}


int main() {
  ll n, m;
  cin >> n >> m;
  vector<vector<int> > adj(n, vector<int>());
  vector<vector<int> > radj(n, vector<int>());
  for (ll i = 0; i < m; i++) {
    int x, y;
    cin >> x >> y;
    
    adj[x - 1].push_back(y - 1);
    radj[y-1].push_back(x-1);

  }
  for(int i=0;i<n;i++)
  {
      if(vis[i]==false)
        dfs(adj,i);

  }
//  cout<<"stack size "<<s1.size()<<endl;

  vis.clear();
  ll z=0;
  while(!s1.empty())
  {
    int a=s1.back();
    if(vis[a]==false)
    {  
      rdfs(radj,a,z);
      z++;
    }
    s1.pob();
  }

  // for(int i=0;i<z;i++)
  // {
  //   cout<<i+1<<" ";
  //   for(int j=0;j<ssc[i].size();j++)
  //     cout<<ssc[i][j]<<" ";
  //   cout<<endl;
  // }
  cout <<z<<endl;
}
