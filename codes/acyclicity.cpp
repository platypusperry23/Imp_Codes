
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

int cc(vector<vector<int> > &adj,int a,int z)
  {
    for(int i=0;i<adj[z].size();i++)
    {
      cout<<adj[z][i]<<"->";
      if(adj[z][i]==a)
        return 1;
      else
      {
        int x =cc(adj,a,adj[z][i]);
        if(x==1)
          return 1;
      }
    }
    return 0;
  }

int acyclic(vector<vector<int> > &adj) {
        
        cout<<adj.size()<<endl;
        int x;
        for(int i=0;i<adj.size();i++)
        {
          
          if(adj[i].size()>0)
           x=cc(adj,i,i);
          if(x==1)
            return 1;
        }
  return 0;
}

int main() {
  size_t n, m;
  cin >> n >> m;
  vector<vector<int> > adj(n, vector<int>());
  for (size_t i = 0; i < m; i++) {
    int x, y;
    cin >> x >> y;
    adj[x - 1].push_back(y - 1);
  }
  cout << acyclic(adj);
}
