ll  dfs(ll  v = 0, ll  prnt = -1, ll  d = 0)
{
    ll  size = 1, maxsize = 0;
    depth[v] = d;
    p[v] = prnt;
    for(ll  i=0;i<g[v].size();++i)
    {
        ll  u = g[v][i].X;
        ll  c = g[v][i].Y.X , idx = g[v][i].Y.Y;
        if(u != prnt)
        {
            ll  subsize = dfs(u, v, d + 1);
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
    for(ll  i=0, currpos = 0; i < n; ++i)
        if(p[i] == -1 || heavy[p[i]] != i)
            for(ll  j = i; j != -1; j = heavy[j])
            {
                root[j] = i;
                num[j] = currpos; b[currpos] = a[j];
                currpos++;
            }
}
 
void build(ll  node, ll  start, ll  end)
{
    if(start == end)
    {
        t[node] = b[start];
        return ;
    }
    ll  mid = (start + end)/2;
    build(2*node, start, mid);
    build(2*node + 1, mid + 1, end);
    t[node] = (t[2*node] > t[2*node + 1]) ? t[2*node] : t[2*node + 1];
}
 
ll  query(ll  node, ll  start, ll  end, ll  l, ll  r)
{
    if(end < l  || start > r)
        return 0;
    if(start >= l && end <= r)
        return t[node];
    ll  mid = (start + end)/2;
    ll  p1 = query(2*node, start, mid, l, r);
    ll  p2 = query(2*node + 1, mid + 1, end, l, r);
    return p1+p2;

}

ll  find(ll  a, ll  b)
{
    ll  res = 0;
    while(root[a] != root[b])
    {
        if(depth[root[a]] < depth[root[b]])
            swap(a, b);
        query(1, 0, n-1, num[root[a]], num[a]);
        a = p[root[a]];
    }
    if(depth[a] > depth[b])
        swap(a, b);
      ll  qw=query(1, 0, n-1, num[a] + 1, num[b]);
      
    res=res+qw;
    return res;
}

int main()
{
    ll  t;
    cin>>t;
    while(t--)
    {
        cin>>n;
        ll  a[n],b[n],c[n];
        for(ll  i=0;i<n-1;i++)
            cin>>a[i]>>b[i];
        ll max=0;
        for(ll  i=0;i<n;i++)
        {
            cin>>c[i];
            if(max<c[i])
                max=c[i];
        }
        sieve(max);
        for(ll i=0;i<n;i++)
            ppw(c[i],i);
        
        ll  d[n];
        for(ll  i=0;i<n-1;i++)
        {
            d[i]=c[a[i]-1]*c[b[i]-1];
            paths(c[])
          //  pfs(c[a[i]-1],c[b[i]-1]);
        }
    
        for(ll  i=0;i<n-1;i++)
        {
            a[i]--;b[i]--;
            g[a[i]].push_back(mp(b[i],mp(d[i],i) ) );
            g[b[i]].push_back(mp(a[i],mp(d[i],i) ) );
        }   
        for(ll  i=0;i<n;++i)
            heavy[i] = -1;

        a[0] = 0;
        dfs(0); hld(); build(1, 0, n-1);
        ll  q;
        cin>>q;
        while(q--)
        {
            ll  a,b;
            cin>>a>>b;
            a--;b--;
            cout<<find(a,b)<<endl;
        }
        for(int i=0;i<n;i++)
        g[i].clear();
    }
    return 0;
} 