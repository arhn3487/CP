#include<bits/stdc++.h>
//#include "D:/debug.h"
using namespace std;

#define ll long long
const int M=1e9+7;
const ll infinity = LLONG_MAX;
int dx[]={1,0,-1,0,1,1,-1,-1};//Right,Down,Left,Up,Right-Up,Right-Down,Left-Up,Left-Down
int dy[]={0,-1,0,1,1,-1,1,-1};
inline ll lcm(ll a,ll b) {return (a*b)/__gcd(a,b);}

#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
#define YES cout<<"YES\n";
#define NO cout<<"NO\n";

void solve()
{
    int n;
    cin>>n;
    int arr[n][n];
    int a[n]={};

    for(int i=0;i<n;i++)
    {
        ll p=(1<<30)-1;
        for(int j=0;j<n;j++)
        {
            cin>>arr[i][j];
            if(i==j) continue;
            p&=arr[i][j];
        }
        a[i]=p;
    }

    // for(auto x : a) cout<<x<<' ';
    // cout<<'\n';

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
           if(i==j) continue;
           if(arr[i][j]!=(a[i]|a[j]))
           {
            //cout<<i<<" "<<j<<endl;
            //cout<<arr[i][j]<<" "<<a[i]<<" "<<a[j]<<endl;
                NO
                return;
           }
        }
    }

    YES
    for(auto x : a) cout<<x<<' ';
    cout<<'\n';
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