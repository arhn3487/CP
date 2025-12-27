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
int dx[]={1,0,-1,0,1,1,-1,-1};
int dy[]={0,-1,0,1,1,-1,1,-1};
inline ll lcm(ll a,ll b) {return (a*b)/__gcd(a,b);}

#define rall(v) v.rbegin(),v.rend()
#define all(v) v.begin(),v.end()
#define print(x) cout<<x<<'\n';
#define yes(x) cout << ((x) ? "YES\n" : "NO\n");

vector<int> a;
vector<array<int,3>> intervals;
vector<int> endPos;

bool cmp(const array<int,3>& A,const array<int,3>& B){
    if(A[1]!=B[1]) return A[1]<B[1];
    return A[0]<B[0];
}

void solve() {
    int n;
    cin>>n;
    a.assign(n+1,0);
    for(int i=1;i<=n;i++) cin>>a[i];

    vector<vector<int>> pos(n+1);
    for(int i=1;i<=n;i++) if(a[i]<=n) pos[a[i]].push_back(i);

    intervals.clear();
    for(int v=1;v<=n;v++){
        int f = pos[v].size();
        if(f<v) continue;
        for(int j=0;j+v-1<f;j++){
            intervals.push_back({pos[v][j], pos[v][j+v-1], v});
        }
    }

    if(intervals.empty()){
        cout<<0<<'\n';
        return;
    }

    sort(all(intervals), cmp);

    int m = intervals.size();
    endPos.assign(m,0);
    for(int i=0;i<m;i++) endPos[i] = intervals[i][1];

    vector<ll> dp(m+1,0);
    for(int i=1;i<=m;i++){
        int start = intervals[i-1][0];
        int w = intervals[i-1][2];
        int p = lower_bound(endPos.begin(), endPos.begin() + (i-1), start) - endPos.begin();
        dp[i] = max(dp[i-1], dp[p] + w);
    }

    cout<<dp[m]<<'\n';
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin>>t;
    for(int i=1;i<=t;i++){
        solve();
    }
}
