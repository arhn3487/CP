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
#define YES cout<<"YES\n";
#define NO cout<<"NO\n";

void solve()
{
    ll n, m, a, b;
    cin >> n >> m >> a >> b;
    
    // Current rectangle boundaries
    ll left = 1, right = m;
    ll top = 1, bottom = n;
    
    int turns = 0;
    
    while (left < right || top < bottom) {
        turns++;
        
    
        ll dist_left = b - left;
        ll dist_right = right - b;
        ll dist_top = a - top;
        ll dist_bottom = bottom - a;
        
   
        ll cut_left = dist_left * (bottom - top + 1);
        ll cut_right = dist_right * (bottom - top + 1);
        ll cut_top = dist_top * (right - left + 1);
        ll cut_bottom = dist_bottom * (right - left + 1);
        
        // Find the maximum area that can be cut off
        ll max_cut = max({cut_left, cut_right, cut_top, cut_bottom});
        
        // Update the rectangle boundaries based on the best cut
        if (max_cut == cut_left) {
            left = b;
        } else if (max_cut == cut_right) {
            right = b;
        } else if (max_cut == cut_top) {
            top = a;
        } else { // cut_bottom
            bottom = a;
        }
        
        // Update a and b to be in the center of the new rectangle
        a = (top + bottom) / 2;
        b = (left + right) / 2;
        
        //dbg(left, right, top, bottom, a, b);
    }
    
    cout << turns << '\n';
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