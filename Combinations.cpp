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
int dx[]={1,0,-1,0,1,1,-1,-1}; // Right, Down, Left, Up, Right-Up, Right-Down, Left-Up, Left-Down
int dy[]={0,-1,0,1,1,-1,1,-1};
inline ll lcm(ll a,ll b) { return (a*b)/__gcd(a,b); }

#define rall(v) v.rbegin(),v.rend()
#define all(v) v.begin(),v.end()
#define print(x) cout<<x<<'\n';
#define YES cout<<"YES\n";
#define NO cout<<"NO\n";

class ncr
{
    private:
        ll mod, N;
        vector<ll> factorial, factorialInverse, naturalNumberInverse;
        
        void preComputeInverse()
        {
            naturalNumberInverse[0] = naturalNumberInverse[1] = 1;
            for(int i = 2; i <= N; i++) 
                naturalNumberInverse[i] = (naturalNumberInverse[mod % i] * (mod - mod / i)) % mod;
        }

        void preComputeFactorialInverse()
        {
            factorialInverse[0] = factorialInverse[1] = 1;
            for(int i = 2; i <= N; i++) 
                factorialInverse[i] = (naturalNumberInverse[i] * factorialInverse[i - 1]) % mod;
        }

        void precomputeFactorials()
        {
            factorial[0] = 1;
            for(int i = 1; i <= N; i++) 
                factorial[i] = (factorial[i - 1] * i) % mod;
        }

    public:
        ncr(ll mod, ll N) : mod(mod), N(N), factorial(N+1), naturalNumberInverse(N+1), factorialInverse(N+1)
        {
            preComputeInverse();
            preComputeFactorialInverse();
            precomputeFactorials();
        }
        
        ll _ncr(ll n, ll r)
        {
            if (r > n || r < 0) return 0;
            return (((factorial[n] * factorialInverse[r]) % mod) * factorialInverse[n - r]) % mod;
        }
};


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ncr X(1000003, 1000005);

    int t = 1;
    cin >> t;

    for(int i = 1; i <= t; i++)
    {
        cout << "Case " << i << ": ";
        ll n, r;
        cin >> n >> r;
        cout << X._ncr(n, r) << '\n';
    }
}
