#include<bits/stdc++.h>
//#include "D:/debug.h"
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

void solve()
{
    int n,val=0;
    string str;
    cin>>n>>str;
    vector<int> v(n,0),x;
    bool as=true,ds=false;

    for(int i=0;i<n;i++)
    {
        if(str[i]=='p') v[i]=i+1;
    }

    for(int i=n-1;i>=0;i--)
    {
        if(str[i]=='s') 
        {
            v[i]=n-i;
            for(int j=i+1;j<n;j++)
            {
                if(v[j]>=v[i])
                {
                    NO
                    return;
                }
            }
        }
    }

    YES
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
        //cout<<"Case "<<i<<": ";
        solve();
    }
}