#pragma GCC optimize("O3")
#include<bits/stdc++.h>
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
#define yes(x) cout << ((x) ? "Yes\n" : "No\n");

void solve() {
    int n; cin >> n;
    if(n==2) cout<<"-1 2\n";
    else
    {
        //cout<<"-1 3 ";
        for(int i=1;i<=n-1;i++)
        {
            if(i%2) cout<<-1<<' ';
            else cout<<3<<' ';
        }
        if(n%2) cout<<-1;
        else cout<<2;
        cout<<'\n';
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
        solve();
    }
}