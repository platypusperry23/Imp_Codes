#include <bits/stdc++.h>
using namespace   std;
#define boost     ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define ll        long long 
#define ld        long double
#define mkp       make_pair
#define pb         push_back  
#define pf         push_front
#define pob       pop_back
#define pof       pop_front
#define mxy     map<pair<ll, ll>, ll>  
#define q1        1000000007
#define bin1      __builtin_popcount 
#define map2d    map<long long,map<long long , long long > >
#define um      unordered_map<ll,ll>
#define INF       0x3f3f3f3f
const int MAX =1e5;
int id[MAX],nodes,edges;
pair <double, pair<int, int> > p[MAX];

void initialize()
{
    for(int i = 0;i < MAX;++i)
        id[i] = i;
}

int root(int x)
{
    while(id[x] != x)
    {
        id[x] = id[id[x]];
        x = id[x];
    }
    return x;
}

void union1(int x, int y)
{
    int p = root(x);
    int q = root(y);
    id[p] = id[q];
}

double kruskal(pair<double , pair<int, int> > p[])
{
    int x, y;
    double cost, minimumCost = 0;
    for(int i = 0;i < edges;++i)
    {
        x = p[i].second.first;
        y = p[i].second.second;
        cost = (p[i].first);
        if(root(x) != root(y))
        {
            minimumCost += cost;
            union1(x, y);
        }    
    }
    return minimumCost;
}


int main() {
  int n;
  double minimumCost;
  initialize();
  std::cin >> n;
  vector<pair<int,int> >v;
  for (int i = 0; i < n; i++) 
  {
    ll x,y;
    cin>>x>>y;
    v.pb(mkp(x,y));  
  }
  nodes=n;


  for(int i=0;i<v.size();i++)
  {
    for(int j=i+1;j<v.size();j++)
    {
      double z=(double)pow((v[i].first-v[j].first),2)+(double)pow((v[i].second-v[j].second),2);
      z=(sqrt(z));
      p[edges++] = mkp(z,mkp(i,j));
      
    }
  }
  
  sort(p,p+edges);
  minimumCost = kruskal(p);
    
   cout<<fixed <<setprecision(10) << minimumCost<< endl;
}
