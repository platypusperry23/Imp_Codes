
# include <bits/stdc++.h>
using namespace std;
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
#define bin1      __builtin_popcount 
#define map2d     map<long long,map<long long , long long > >
#define um        unordered_map<ll,ll>
# define INF      0x3f3f3f3f
typedef pair<int, int> iPair; 
priority_queue< iPair, vector <iPair> , greater<iPair> > pq;

int distance(vector<vector<int> > &adj, vector<vector<int> > &cost, int s, int t,int n)
{
  vector<int> dist(n,INF);
  pq.push(mkp(0,s));
  dist[s]=0;
  while(!pq.empty())
  {
    ll v=pq.top().second;
    pq.pop();
    for(int i=0;i<adj[v].size();i++)
    {
      ll z=adj[v][i];
      ll w=cost[v][i];
      if(dist[z]>dist[v]+w)
      {
        dist[z]=dist[v]+w;
        pq.push(mkp(dist[z],z));
      }
    }
  } 
  if(dist[t]!=INF)
  return dist[t] ;
  else
  return -1;   
}

int main() {
  int n, m;
  std::cin >> n >> m;
  vector<vector<int> > adj(n, vector<int>());
  vector<vector<int> > cost(n, vector<int>());
  for (int i = 0; i < m; i++) {
    int x, y, w;
    std::cin >> x >> y >> w;
    adj[x - 1].push_back(y - 1);
    cost[x - 1].push_back(w);
  }
  int s, t;
  std::cin >> s >> t;
  s--, t--;
  std::cout << distance(adj, cost, s, t,n);
}
