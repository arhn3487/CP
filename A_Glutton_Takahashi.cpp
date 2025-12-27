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

    int n;
    cin>>n;
    int cnt=0,flag=1;

    while(n--)
    {
        if(cnt==2) flag=1;
        string s;
        cin>>s;
        if(s=="sweet") cnt++;
        else cnt=0;
    }
    if(flag) cout<<"NO\n";
    else cout<<"YES\n";
}