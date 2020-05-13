#include <bits/stdc++.h>
 
using namespace std;
 
#define X first 
#define Y second 
#define mp make_pair
#define MAX(x, y) (((x) > (y))? (x) : (y))
 
const int N = 1e5+5;
 
int n, heavy[N], root[N], p[N];
int pos[N], num[N], depth[N], a[N], b[N], vtx[N];
 int t[N];
vector<pair<int, pair<int, int> > > g[N];


 
int dfs(int v = 0, int prnt = -1, int d = 0)
{
    int size = 1, maxsize = 0;
    depth[v] = d;
    p[v] = prnt;
    for(int i=0;i<g[v].size();++i)
    {
        int u = g[v][i].X;
        int c = g[v][i].Y.X , idx = g[v][i].Y.Y;
        if(u != prnt)
        {
            int subsize = dfs(u, v, d + 1);
            if(subsize > maxsize)
            {
                maxsize = subsize;
                heavy[v] = u;
            }
            vtx[idx] = u;
            size += subsize;
            a[u] = c;
        }
    }
    return size;
}
 
void hld()
{
    for(int i=0, currpos = 0; i < n; ++i)
        if(p[i] == -1 || heavy[p[i]] != i)
            for(int j = i; j != -1; j = heavy[j])
            {
                root[j] = i;
                num[j] = currpos; b[currpos] = a[j];
                currpos++;
            }
}
 
void build(int node, int start, int end)
{
    if(start == end)
    {
        t[node] = b[start];
        return ;
    }
    int mid = (start + end)/2;
    build(2*node, start, mid);
    build(2*node + 1, mid + 1, end);
    t[node] = t[2*node] + t[2*node + 1];
}
 
// void printg()
// {
//     for(int i=1;i<40;i++)
//         cout<<i<<" "<<t[i]<<endl;
// }
int query(int node, int start, int end, int l, int r)
{
    if(end < l  || start > r)
        return 0;
    if(start >= l && end <= r)
        return t[node];
    int mid = (start + end)/2;
    int p1 = query(2*node, start, mid, l, r);
    int p2 = query(2*node + 1, mid + 1, end, l, r);

    return p1+p2;
}
  
int find(int a, int b)
{
    int res = 0;
    while(root[a] != root[b])
    {
        if(depth[root[a]] < depth[root[b]])
            swap(a, b);
        int qw=query(1, 0, n-1, num[root[a]], num[a]);
        cout<<qw <<" 1" <<endl; 
        res=res+qw;
        a = p[root[a]];
    }
    if(depth[a] > depth[b])
        swap(a, b);
      int qw=query(1, 0, n-1, num[a] + 1, num[b]);
        cout<<qw<<" 2"<<endl;
    res=res+qw;
    return res;
}
 
int main()
{
    int t;
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d", &n);
        int a[n],b[n],c[n];
        for(int i=0;i<n-1;i++)
            cin>>a[i]>>b[i];
        for(int i=0;i<n;i++)
            cin>>c[i];
        int d[n];
        for(int i=0;i<n-1;i++)
        {
            int aa=c[a[i]-1];
            int bb=c[b[i]-1];
            d[i]=aa*bb;
           // cout<<a[i]<<" "<<b[i]<<" "<<d[i]<<endl;
        }
        for(int i=0;i<n-1;i++)
        {
            a[i]--;b[i]--;
            g[a[i]].push_back(mp(b[i],mp(d[i],i) ) );
            g[b[i]].push_back(mp(a[i],mp(d[i],i) ) );
        }   
        for(int i=0;i<n;++i)
            heavy[i] = -1;

        a[0] = 0;
        dfs(0); hld(); build(1, 0, n-1);
        
        // printg();
        int q;
        cin>>q;
        while(q--)
        {
            int a,b;
            cin>>a>>b;
            a--;b--;
            cout<<find(a,b)<<endl;
        }
        for(int i=0;i<n;++i)
            g[i].clear();
    }
    return 0;
}