#pragma GCC optimize("O3")
#include<bits/stdc++.h>
#ifndef ONLINE_JUDGE
#else
#define dbg(x...)
#define dbgc(x...)
#endif
using namespace std;

#define ll long long
const int M=1e9+7;
const ll infinity = LLONG_MAX;
int dx[]={1,0,-1,0,1,1,-1,-1};
int dy[]={0,-1,0,1,1,-1,1,-1};
inline ll lcm(ll a,ll b) {return (a*b)/__gcd(a,b);}

#define rall(v) v.rbegin(),v.rend()
#define all(v) v.begin(),v.end()
#define print(x) cout<<x<<'\n';
#define yes(x) cout << ((x) ? "YES\n" : "NO\n");

void solve()
{
    int n;
    string s;
    cin >> n >> s;
    
    string target;
    for(int i = 0; i < n; i++) {
        target += (i % 2 == 0 ? '0' : '1');
    }
    
    int ans = INT_MAX;

    for(int start = 0; start <= 1; start++) {
        string t = s;
        int ops = 0;
        
        if(start == 1) {
            ops++;
            t[0] = (t[0] == '0' ? '1' : '0');
            if(n > 1) t[1] = (t[1] == '0' ? '1' : '0');
        }
        

        for(int i = 1; i < n; i++) {
            if(t[i-1] != target[i-1]) {

                ops++;
                t[i-1] = (t[i-1] == '0' ? '1' : '0');
                t[i] = (t[i] == '0' ? '1' : '0');
                if(i+1 < n) t[i+1] = (t[i+1] == '0' ? '1' : '0');
            }
        }
        
        // Check if final matches target
        if(t == target) {
            ans = min(ans, ops);
        }
    }
    
    if(ans == INT_MAX) {
        print(-1)
    } else {
        print(ans)
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t=1;
    cin>>t;

    for(int i=1;i<=t;i++)
    {
        //cout<<"Case "<<i<<": ";
        solve();
    }
}