#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD ((ll)1e9 + 7)
int main()
{
      ll t;
      cin >> t;
      while (t--)
      {
            ll n, k, m;
            cin >> n >> k >> m;
            vector<ll> v[10005];
            ll a[10005];
            memset(a, 0, sizeof(a));
            a[0] = 1;
            for (ll i = 0; i <= k; i++)
                  a[0] = 1;
            for (ll i = 1; i <= k; i++)
                  v[i % m].push_back(i);
            for (ll i = 1; i <= n; i++)
            {
                  ll b;
                  cin >> b;
                  b = b % m;
                  ll s = v[b].size();
                  for (ll j = s - 1; j >= 0; j--)
                  {
                        ll d = v[b][j];
                        a[d] = (a[d] % MOD + a[d - 1] % MOD) % MOD;
                  }
            }
            cout << a[k] << endl;
      }
}
