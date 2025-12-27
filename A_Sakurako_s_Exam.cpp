#include<bits/stdc++.h>
//#include "D:/debug.h"
using namespace std;

#define ll long long
const ll infinity = LLONG_MAX;
int dx[]={1,0,-1,0,1,1,-1,-1};//Right,Down,Left,Up,Right-Up,Right-Down,Left-Up,Left-Down
int dy[]={0,-1,0,1,1,-1,1,-1};
ll lcm(ll a,ll b) {return (a*b)/__gcd(a,b);}

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
        stack<int> st;
        int a,b;
        cin>>a>>b;
        b=b%2;

        if(b==1 && a%2==0 && a>=2) cout<<"YES\n";
        else if((b==0 && a==0 )|| (b==0 && a%2==0)) cout<<"YES\n";
        else cout<<"NO\n";
    }
}