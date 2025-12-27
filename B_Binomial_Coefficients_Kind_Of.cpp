#include<bits/stdc++.h>
//#include "D:/debug.h"
using namespace std;

#define ll long long
const int M=1e9+7;
const ll infinity = LLONG_MAX;
int dx[]={1,0,-1,0,1,1,-1,-1};//Right,Down,Left,Up,Right-Up,Right-Down,Left-Up,Left-Down
int dy[]={0,-1,0,1,1,-1,1,-1};
inline ll lcm(ll a,ll b) {return (a*b)/__gcd(a,b);}

ll bin_exp(ll base,ll exp,ll mod){
    ll res=1;
    while(exp){
        if(exp%2) res=(res*base)%mod;
        base=(base*base)%mod;
        exp/=2;
    }
    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin>>t;

    vector<ll> n(t),k(t);

    for(auto &x : n) cin>>x;
    for(auto &x : k) cin>>x;


    for(int i=0;i<t;i++) 
    {
        int x=pow(2,k[i]);
        cout<<bin_exp(2,k[i],M)<<endl;
        //x%=M;
        //cout<<x<<endl;
    }
}