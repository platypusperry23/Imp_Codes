#include <bits/stdc++.h>
#include <iostream>
#include <vector>

using namespace std;
bool vis2[1001];
int cl(vector<vector<int> > &adj,int x)
{
	

	if(vis2[x]==false)
	{
		vis2[x]=true;
		for(int i=0;i<adj[x].size();i++)
		{	
			// cout<<adj[x][i]<<"->";
			int z=cl(adj,adj[x][i]);
			vis2[adj[x][i]]=false;
			if(z==1)
				return 1;
		}
	}
	else
	return 1;

	return 0;
}

int acyclic(vector<vector<int> > &adj,int n)
{
	int z;
	for(int i=0;i<n;i++)
	{	
		memset(vis2,false,sizeof(vis2));
		z=cl(adj,i);
		if(z==1)
			return 1;
			
	}
	return z;
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
  }
  
  cout << acyclic(adj,n);
}
