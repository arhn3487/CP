#include<bits/stdc++.h>
#include "D:/debug.h"
using namespace std;

#define ll long long
const ll infinity = LLONG_MAX;
int dx[]={1,0,-1,0,1,1,-1,-1};
int dy[]={0,-1,0,1,1,-1,1,-1};
ll lcm(ll a,ll b) {return (a*b)/__gcd(a,b);}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int a,b,c;
    string str;

    cin>>a>>b>>c>>str;

    if(str=="Blue") cout<<min(a,b)<<endl;
    else if(str=="Red") cout<<min(b,c);
    else cout<<min(a,c)<<endl;
}