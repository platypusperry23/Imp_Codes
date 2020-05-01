class Solution
{
public:
      int findCheapestPrice(int n, vector<vector<int>> &adjj, int src, int dst, int k)
      {
            vector<vector<int>> adj(n, vector<int>());
            map<int, map<int, int>> wt;

            for (int i = 0; i < adj.size(); i++)
            {
                  int u = adjj[i][0];
                  int v = adjj[i][1];
                  int wit = adjj[i][2];
                  adj[u].push_back(v);
                  wt[u][v] = wit;
            }
            vector<vector<int> > lev(k+1,vector<int>());
            int dp[k+1][n];
            memset(dp,0,sizeof(dp));
            for(int i=0;adj[src].size();i++)
            {     
                  int v=adj[src][i];
                  lev[1].push_back(v);
                  dp[1][v]=wt[src][v];
            }
            for(int i=1;i<=k;i++)
            {
                  for(int j=0;j<lev[i].size();j++)
                  {
                        int u=lev[i][j];
                        for(int q=0;q<adj[u].size();q++)
                        {
                               
                        }
                  }
                  
            }

            return 0;
      }
};