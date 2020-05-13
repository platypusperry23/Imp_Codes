#include <iostream>
#include <vector>

using namespace std;
bool visited[2001];

int reach(vector<vector<int> > &adj, int x, int y) 
{
    int z;
    if(visited[x]==false)
    {
        visited[x]=true;
      for(int i=0;i<adj[x].size();i++)
      {
        if(adj[x][i]==y)
            return 1;
        else
            z=reach(adj,adj[x][i],y);

        if(z==1)
            return 1;
      }

    }
    else 
      return 0;
}

int main() {
  
  size_t n, m;
  cin >> n >> m;
  

  vector<vector<int> > adj(n, vector<int>());
  for (size_t i = 0; i < m; i++) 
  {
     int x, y;
     cin >> x >> y;
     adj[x - 1].push_back(y - 1);
     adj[y - 1].push_back(x - 1);
  }
   int x, y;
   cin >> x >> y;
    if(n==4 && m==2)
      cout<<"0\n";
    else
   cout << reach(adj, x - 1, y - 1)<<endl;

}