#include<bits/stdc++.h>
//#include "D:/debug.h"
using namespace std;

#define ll long long
const int M=1e9+7;
const ll infinity = LLONG_MAX;
int dx[]={1,0,-1,0,1,1,-1,-1};//Right,Down,Left,Up,Right-Up,Right-Down,Left-Up,Left-Down
int dy[]={0,-1,0,1,1,-1,1,-1};
ll lcm(ll a,ll b) {return (a*b)/__gcd(a,b);}

ll pow(ll a,ll b,ll c)
{
    if(b==0) return 1;
    ll res=pow(a,b/2,c);
    res=(res*res)%c;
    if(b%2) return (res*a)%c;
    else return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll N,K,A;
    int t=1;

    while(cin>>N>>K>>A && (N|K|A))
    {
        cout<<"Case "<<t<<":\n";
        int c;
        cin>>c;
        
        while(c--)
        {
            ll a;
            cin>>a;
            cout<<(A*pow(K,N,a))%a;
            if(c) cout<<" ";
        }
        t++;
        cout<<"\n";
    }
}