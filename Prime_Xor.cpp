#include<bits/stdc++.h>
//#include "D:/debug.h"
using namespace std;

#define ll long long
const int M=1e9+7;
const ll infinity = LLONG_MAX;
int dx[]={1,0,-1,0,1,1,-1,-1};//Right,Down,Left,Up,Right-Up,Right-Down,Left-Up,Left-Down
int dy[]={0,-1,0,1,1,-1,1,-1};
inline ll lcm(ll a,ll b) {return (a*b)/__gcd(a,b);}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin>>t;

    while(t--)
    {
        ll x,y,z;
        cin>>x>>y;
        z=x^y;
        //int arr[3]={2};
        //set<int> st;
        vector<int> v;
        v.push_back(2);
        if(x&1) v.push_back(2^x);
        if(y&1) v.push_back(2^y);
        if(z&1) v.push_back(2^z);
        sort(v.begin(),v.end());

        for(auto x : v) cout<<x<<" ";

        cout<<"\n";
    }
}