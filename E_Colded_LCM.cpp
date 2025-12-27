#pragma GCC optimize("O3")
#include<bits/stdc++.h>
#ifndef ONLINE_JUDGE
#include "D:/debug.h"
#else
#define dbg(x...)
#define dbgc(x...)
#endif
using namespace std;

#define ll long long
const int M=1e9+7;
const ll infinity = LLONG_MAX;
int dx[]={1,0,-1,0,1,1,-1,-1};//Right,Down,Left,Up,Right-Up,Right-Down,Left-Up,Left-Down
int dy[]={0,-1,0,1,1,-1,1,-1};
inline ll lcm(ll a,ll b) {return (a*b)/__gcd(a,b);}

#define rall(v) v.rbegin(),v.rend()
#define all(v) v.begin(),v.end()
#define print(x) cout<<x<<'\n';
#define YES cout<<"YES\n";
#define NO cout<<"NO\n";

void solve()
{
    ll l,r,mn=LLONG_MAX;
    cin>>l>>r;
    if(r>=2*l)
    {
        cout<<2*l<<'\n';
        return;
    }
    //cout<<l<<' '<<l+1<<'\n';
    //cout<<lcm(l,l+1)<<'\n';

    for(ll g=1;g<l;g++)
    {
        ll a=g*(l+g-1)/g;
        ll b=a+1;
        mn=min(mn,a*b*g);
        debug(a,b,g);
    }

    cout<<mn<<'\n';
}

int t; ll L, R;

int main() {
  cin >> t;
  while (t--) {
    scanf("%lld %lld", &L, &R);
    if (R >= 2 * L) {
      printf("%lld\n", 2 * L);
      continue;
    }
    ll x = L - 1, ans = LLONG_MAX;
    for (ll i = 1, j; i <= x; i = j + 1) {
      ll fix = x / i; j = x / fix;
      debug(i, j, fix);
      if (i <= R / (fix + 2)) ans = min(ans, i * (fix + 1) * (fix + 2));
    }
    printf("%lld\n", ans);
  }
  return 0;
}

