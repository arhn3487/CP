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
#define yes(x) cout << ((x) ? "YES\n" : "NO\n");

const int N=1e6+5;
vector<int> divs[N];
ll arr[N],cnt_mul[N],ans[N],freq[N];

void div_cal()
{
    for(int i=1;i<N;i++)
    {
        for(int j=i;j<N;j+=i)
        {
            divs[j].push_back(i);
        }
    }
}

void solve()
{
    int n,total=0;cin>>n;

    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
        freq[arr[i]]++;
    }

    // for(int i=1;i<N;i++)
    // {
    //     cnt_mul[i]+=1LL*(freq[i]*(freq[i]-1))/2;
    // }

    for(int i = 1; i < N; i++)
    {
        ll count = 0;
        for(int j = i; j < N; j += i)
        {
            count += freq[j];
        }
        cnt_mul[i] = count * (count - 1) / 2;
    }

    for(int i=N-1;i>=1;i--)
    {
        ans[i]=cnt_mul[i];
        for(int j=2*i;j<N;j+=i)
        {
            ans[i]-=ans[j];
        }
    }

    cout<<ans[1]<<'\n';

}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t=1;
    //cin>>t;

    //div_cal();

    for(int i=1;i<=t;i++)
    {
        //cout<<"Case "<<i<<": ";
        solve();
    }
}
