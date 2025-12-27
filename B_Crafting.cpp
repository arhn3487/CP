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
    int n;
    cin>>n;
    vector<int> v(n,0),a(n),b(n);
    int ind=-1,k=0;

    for(int i=0;i<n;i++) cin>>a[i];
    for(int i=0;i<n;i++) cin>>b[i];

    for(int i=0;i<n;i++)
    {
        if(a[i]<b[i])
        {
            ind=i;
            k++;
        }
    }
    //cout<<k<<endl;
    if(ind<0)
    {
        YES
        return;
    }
    if(k>1)
    {
        NO
        return;
    }
    int p=b[ind]-a[ind];

    for(int i=0;i<n;i++)
    {
        if(i!=ind && a[i]-p<b[i])
        {
            NO
            return;
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