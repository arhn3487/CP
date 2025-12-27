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

    //float a;
    //cin>>a;
    string s;
    cin>>s;
    int n=s.length();
    n--;
    //cout<<n<<endl;

    if(n>0 && s[n]=='0')
    {
        while( n>0 &&s[n]=='0' ) n--;
    }

    //cout<<n<<endl;

    if(s[n]=='.') n--;
    cout<<s.substr(0,n+1)<<endl;
}