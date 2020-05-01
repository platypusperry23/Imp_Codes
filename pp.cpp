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



ll eval(ll a, ll b, char  op ) {
  if (op == '*') {
    return a * b;
  } else if (op == '+') {
    return a + b;
  } else if (op == '-') {
    return a - b;
  } else {
    assert(0ll);
  }
}
int main() {
  string s;
  cin >> s;


  int length = s.size();
  int n = (length + 1) / 2;
  int mia[n][n];
  int maa[n][n];
  memset(mia,0,sizeof(mia)); 
  memset(maa,0,sizeof(maa));
  for (ll i = 0; i < n; i++)
  {
    mia[i][i] = stoll(s.substr(2*i,1));
    maa[i][i] = stoll(s.substr(2*i,1));
  }

  for (int s = 0; s < n - 1; s++)
  {
    for (int i = 0; i < n - s - 1; i++)
    {
      int j = i + s + 1;
      ll minVal = LLONG_MAX;
        ll maxVal = LLONG_MIN;

      for (ll k = i; k < j; k++ )
        {
              ll z=2*k+1;
        ll a = eval(mia[i][k],mia[k + 1][j],s[z]);
        ll b = eval(mia[i][k],maa[k + 1][j],s[z]);
        ll c = eval(maa[i][k],mia[k + 1][j],s[2*k+1] );
        ll d = eval(maa[i][k],maa[k + 1][j],s[2*k+1 ]);
        minVal = min(minVal,min(a,min(b,min(c,d))));
        maxVal = max(maxVal,max(a,max(b,max(c,d))));
        }
      mia[i][j] = minVal;
      maa[i][j] = maxVal;
    }
  }
  cout<<maa[0][n-1]<<endl;
  
}