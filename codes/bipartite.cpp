
# include <bits/stdc++.h>
using namespace   std;
#define boost     ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define ll        long long 
#define ld        long double
#define pi        3.14  
#define mkp       make_pair
#define pb        push_back  
#define pf        push_front
#define pob       pop_back
#define pof       pop_front
#define ins       insert
#define mxy       map<pair<ll, ll>, ll>  
#define q1        1000000007
#define fl        forward_list
#define bin1    __builtin_popcount 
#define map2d     map<long long,map<long long , long long > >
#define um        unordered_map<ll,ll>

queue<ll>q;
ll dist[(ll)1e5];

int bipartite(vector<vector<int> > &adj) 
{
  int s=0;
  dist[s]=0;
  q.push(s);
  while(!q.empty())
  {
    int z=q.front();
    q.pop();
    for(int i=0;i<adj[z].size();i++)
    {
      if(dist[adj[z][i]]==-1)
      {
        dist[adj[z][i]]=dist[z]+1;
        q.push(adj[z][i]);
      }
      else if(dist[adj[z][i]]==dist[z])
      {
        return 0;
      }
    }
  }
  return 1;
}


int main() {
  memset(dist,-1,sizeof(dist));
  int n, m;
  std::cin >> n >> m;
  vector<vector<int> > adj(n, vector<int>());
  for (int i = 0; i < m; i++) {
    int x, y;
    std::cin >> x >> y;
    adj[x - 1].push_back(y - 1);
    adj[y - 1].push_back(x - 1);
  }
  std::cout << bipartite(adj);
}
