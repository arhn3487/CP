#include<bits/stdc++.h>
//#include "D:/debug.h"
using namespace std;

#define ll long long
const int M=1e9+7;
const ll infinity = LLONG_MAX;
int dx[]={1,0,-1,0,1,1,-1,-1};//Right,Down,Left,Up,Right-Up,Right-Down,Left-Up,Left-Down
int dy[]={0,-1,0,1,1,-1,1,-1};
inline ll lcm(ll a,ll b) {return (a*b)/__gcd(a,b);}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin>>t;

    while(t--)
    {
        int n,k;
        cin>>n>>k;
        vector<int> v(n+1);

        for(int i=1;i<=n;i++) v[i]=n-i+1;

        for(int i=1;i<n;i++)
        {
            if(i%k==v[i]%k) swap(v[i],v[i+1]);
        }

        if(n==1) cout<<-1;
        else for(int i=1;i<=n;i++) cout<<v[i]<<" ";
        cout<<'\n';
    }
}