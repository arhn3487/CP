#include<bits/stdc++.h>
using namespace std;

#define ll long long
const ll infinity = LLONG_MAX;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll n;
    cin>>n;
    string str;

    vector<vector<ll>> v(n,vector<ll>(n,infinity));

    for(ll i=1;i<n;i++)
    {
        for(ll j=0;j<i;j++)
        {
            cin>>str;
            if(str!="#")
            {
                v[i][j]=v[j][i]=stoll(str);
            }
        }
    }
    for(ll i=0;i<n;i++)
    {
        for(ll j=0;j<n;j++)
        {
            cin>>str;
            if(str!="#")
            {
                cout<<v[i][j]<<" ";
            }
            cout<<endl;
        }
    }
}