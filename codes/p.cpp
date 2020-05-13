# include <bits/stdc++.h>
using namespace std;
#define boost     ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define ll        long long 
#define ld        long double
#define pi        3.14	
#define mkp       make_pair
#define pb     	  push_back	
#define pf     	  push_front
#define pob       pop_back
#define pof       pop_front
#define ins		  insert
#define mxy 	  map<pair<ll, ll>, ll>  
#define q1        1000000007
#define fl        forward_list
#define bin1      __builtin_popcount 
#define map2d	  map<long long,map<long long , long long > >
#define um		  unordered_map<ll,ll>
#define X first 
#define Y second 
const ll  N=(ll )1e5+5;

map2d mp;

map2d mp2;

set<ll> pris[N];

set<ll> s2[N];

ll   heavy[N], root[N], p[N];

ll  n, pos[N], num[N], depth[N], te[6*N], a[N], b[N], vtx[N],kth;

ll  s[N];
vector<pair<ll  , pair<ll  , ll  > > > g[N];

set<ll>anp; 

// void sieve(ll n) 
// { 
//    vector <bool> prime(n+1, false);   
//     for (ll  i=2; i<=n; i+=2) 
//         s[i] = 2; 
//     for (ll  i=3; i<=n; i+=2) 
//     { 
//         if (prime[i] == false) 
//         { 
//             s[i] = i; 
//             for (ll  j=i; j*i<=n; j+=2) 
//             { 
//                 if (prime[i*j] == false) 
//                 { 
//                     prime[i*j] = true; 
//                     s[i*j] = i; 
//                 } 
//             } 
//         } 
//     } 
// } 

// void ppw(ll n,ll i) 
// { 
//     ll curr = s[n];
//     ll cnt = 1; 
//     while (n > 1) 
//     { 
//         n /= s[n]; 

//          if (curr == s[n]) 
//         { 
//             cnt++; 
//             continue; 
//         } 
//         pris[i].insert(curr);
//         mp[i][curr]=cnt;
//         curr = s[n]; 
//         cnt = 1; 
//     } 
// } 

// void paths(ll a,ll b,ll k)
// {
// 	for(auto i:pris[a])
// 	{
// 		s2[k].insert(i);
// 		mp2[k][i]=(mp2[k][i]+mp[a][i]);
// 	}
// 	for(auto i:pris[b])
// 	{
// 		s2[k].insert(i);
// 		mp2[k][i]=mp2[k][i]+mp[b][i];
// 	}
	

//  }

// void segtreepath(ll z,ll a,ll b)
// {
//     for(auto itr:s2[])
// }



// void factors(ll a, ll b,set<ll>anp , um m)
// {
// 	for(auto i:s2[a])
// 	{
// 		anp.insert(i);
// 		m[i]=m[i]+mp2[a][i];
// 	}
// 	for(auto i:s2[b])
// 	{
// 		anp.insert(i);
// 		m[i]=m[i]+mp2[b][i];
// 	}	
// }

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
void pa()
{   cout<<"Array a"<<endl;
    for(ll  i=0;i<20;i++)
        cout<<a[i]<<" ";
    cout<<endl;
    cout<<"Array b"<<endl;
    for(ll  i=0;i<20;i++)
        cout<<b[i]<<" ";
    cout<<endl;
}
 
void hld()
{
    for(ll  i=0, currpos = 0; i < n; ++i)
        if(p[i] == -1 || heavy[p[i]] != i)
            for(ll  j = i; j != -1; j = heavy[j])
            {
                root[j] = i;
                num[j] = currpos; 
                b[currpos] = a[j];
                hash1[currpos]=j;
                currpos++;
            }
}
 
void build(ll  node, ll  start, ll  end)
{
    if(start == end)
    {
        te[node] = b[start];
        hash[node]=hash1[start];
        return ;
    }
    ll  mid = (start + end)/2;
    build(2*node, start, mid);
    build(2*node + 1, mid + 1, end);
    hash[++kth]=node;
    te[node] = te[2*node] * te[2*node + 1];
    paths(hash[2*node],hash[2*node+1],kth);

}
ll  query(ll  node, ll  start, ll  end, ll  l, ll  r)
{
    if(end < l  || start > r)
        return 1;
    if(start >= l && end <= r)
    {

        return te[node];
    }
    ll  mid = (start + end)/2;
    ll  p1 = query(2*node, start, mid, l, r);
    ll  p2 = query(2*node + 1, mid + 1, end, l, r);

 
    return p1*p2;
}
  
ll  find(ll  a, ll  b)
{
    ll  res = 1;
    while(root[a] != root[b])
    {
        if(depth[root[a]] < depth[root[b]])
            swap(a, b);
        ll  qw=query(1, 0, n-1, num[root[a]], num[a]);
        
        res=res*qw;
        a = p[root[a]];
    }
    if(depth[a] > depth[b])
        swap(a, b);
      ll  qw=query(1, 0, n-1, num[a] + 1, num[b]);
        cout<<qw<<" 2"<<endl;
    res=res*qw;
    return res;
}
 
int  main()
{
    ll  t;
    cin>>t;
    while(t--)
    {

        cin>>n;
        ll  a[n],b[n],c[n];
        for(ll  i=0;i<n-1;i++)
            cin>>a[i]>>b[i];
        ll  max=0;
        for(ll  i=0;i<n;i++)
        {
            cin>>c[i];
           ppw(c[i],i);
            if(c[i]>max)
            	max=c[i];
        }
        sieve(max);

        ll  d[n];
        for(ll  i=0;i<n-1;i++)
        {
            a[i]--;b[i]--;
            d[i]=c[a[i]]*c[b[i]];
            //paths(a[i],b[i],i+1);
            g[a[i]].push_back(mkp(b[i],mkp(i+1,i)));
            g[b[i]].push_back(mkp(a[i],mkp(i+1,i)));

        }   
        for(ll  i=0;i<n;++i)
            heavy[i] = -1;

        a[0] = 0;
        
        dfs(0); hld(); build(1, 0, n-1);
        pa();
        
        
        ll q;
        cin>>q;
        while(q--)
        {
            ll a,b;
            cin>>a>>b;
            a--;b--;
            cout<<find(a,b)<<endl;
            
        }
        for(ll  i=0;i<n;++i)
            g[i].clear();
    }
    return 0;
}