#pragma GCC optimize("O3,unroll-loops")
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
const ll infinity=LLONG_MAX;
int dx[]={1,0,-1,0,1,1,-1,-1};
int dy[]={0,-1,0,1,1,-1,1,-1};
inline ll lcm(ll a,ll b){return (a*b)/__gcd(a,b);}
#define rall(v) v.rbegin(),v.rend()
#define all(v) v.begin(),v.end()
#define print(x) cout<<x<<'\n';
#define yes(x) cout<<((x)?"YES\n":"NO\n");

void solve(){
    ll n,q;
    string s;
    cin>>n>>q>>s;
    while(q--){
        ll a;cin>>a;
        ll cnt=0;

        if(count(all(s),'B')==0)
        {
            ll ak_cycle=n;
            cout<<a<<'\n';
            continue;
        }
        while(a>0){
            for(int i=0;i<n && a>0;i++){
                if(s[i]=='A') a--;
                else a/=2;
                cnt++;
            }
        }
        cout<<cnt<<'\n';
    }
    //cout<<'\n';
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t=1;
    cin>>t;
    for(int i=1;i<=t;i++){
        solve();
    }
}
