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

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t=1;
    cin>>t;

    while(t--)
    {
        int n,k,bijor=0;
        string str;
        cin>>n>>k>>str;

        int arr[26]={};

        for(auto ch : str)
            arr[ch-'a']++;

        for(int i=0;i<26;i++)
            if(arr[i]%2!=0) bijor++;
        
        //debug(bijor);
        if(bijor-1<=k) YES
        // else if(bijor-1==k) YES
        // else if(bijor==k) YES
        else NO
    }
}
