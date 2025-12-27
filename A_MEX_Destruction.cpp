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
    int n,all_zero=1;
    cin>>n;
    vector<int> v(n);

    for(int i=0;i<n;i++) 
    {
        cin>>v[i];
        if(v[i]!=0) all_zero=0;
    }

    int i=0,j=n-1;

    if(all_zero)
    {
        cout<<0<<endl;
        return;
    }

    while(v[i]==0) i++;
    while(j>=i && v[j]==0) j--;

    for(i;i<=j && i<n;i++)
    {
        if(v[i]==0)
        {
            print(2);
            return;
        }
    }
    print(1);
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