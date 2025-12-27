#include<bits/stdc++.h>
//#include "D:/debug.h"
using namespace std;

#define ll long long
const ll infinity = LLONG_MAX;
int dx[]={1,0,-1,0,1,1,-1,-1};//Right,Down,Left,Up,Right-Up,Right-Down,Left-Up,Left-Down
int dy[]={0,-1,0,1,1,-1,1,-1};
ll lcm(ll a,ll b) {return (a*b)/__gcd(a,b);}
const int N=1e5+10;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    t=1;
    cin>>t;

    while(t--)
    {
        ll n,m,l,r,mx=0;
        cin>>n>>m;
        vector<ll> v(n);
        vector<ll> x(N,0);

        for(int i=0;i<n;i++) 
        {
            cin>>v[i];
            mx=max(mx,v[i]);
        }


        for(int i=0;i<m;i++)
        {
            char ch;
            cin>>ch;
            cin>>l>>r;

            if(ch=='+' && l<=mx && mx<=r) mx++;
            else if(ch=='-' && l<=mx && mx<=r)mx--;

            cout<<mx<<" ";

        }
        cout<<endl;
    }
}