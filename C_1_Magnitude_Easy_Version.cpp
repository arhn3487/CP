#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#ifndef ONLINE_JUDGE
#include "D:/debug.h"
#else
#define dbg(x...)
#define dbgc(x...)
#endif
using namespace std;

#define ll long long
const int M = 1e9 + 7;
const ll infinity = LLONG_MAX;
int dx[] = {1, 0, -1, 0, 1, 1, -1, -1}; // Right,Down,Left,Up,Right-Up,Right-Down,Left-Up,Left-Down
int dy[] = {0, -1, 0, 1, 1, -1, 1, -1};
inline ll lcm(ll a, ll b) { return (a * b) / __gcd(a, b); }

#define rall(v) v.rbegin(), v.rend()
#define all(v) v.begin(), v.end()
#define print(x) cout << x << '\n';
#define YES cout << "YES\n";
#define NO cout << "NO\n";

ll ans = LLONG_MIN;
int sz;

void find(int ind, vector<ll> &v, ll sum)
{
  //debug(ind, sum);
  if (ind == sz)
  {
    ans = max(ans, sum);
    ans = max(ans, abs(sum));
    return;
  }
  find(ind + 1, v, sum + v[ind]);
  find(ind + 1, v, abs(sum + v[ind]));
}

void solve()
{
  ans = LLONG_MIN;
  int n;
  cin >> n;
  vector<ll> v, f;

  for (int i = 0; i < n; i++)
  {
    ll a;
    cin >> a;
    v.push_back(a);
  }

  // int i = 0;
  // while (i < n)
  // {
  //   ll sum = 0;
  //   if (v[i] >= 0)
  //   {
  //     while (i < n && v[i] >= 0)
  //     {
  //       sum += v[i];
  //       i++;
  //     }
  //   }
  //   else
  //   {
  //     while (i < n && v[i] < 0)
  //     {
  //       sum += v[i];
  //       i++;
  //     }
  //   }
  //   f.push_back(sum);
  // }
  sz = v.size();
  find(0, v, 0);

  
  print(ans)
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int t = 1;
  cin >> t;

  for (int i = 1; i <= t; i++)
  {
    // cout<<"Case "<<i<<": ";
    solve();
  }
}