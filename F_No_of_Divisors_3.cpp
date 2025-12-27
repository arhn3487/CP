#include<bits/stdc++.h>
using namespace std;

#define ll long long
const ll infinity = LLONG_MAX;

bool cmp(pair<ll, ll> a, pair<ll, ll> b)
{
    if (a.first == b.first) return a.second > b.second;
    return a.first < b.first;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin>>t;

    vector<pair<ll,ll>> v;

    for(ll i=1;i<=1000;i++)
    {
        ll cnt=0;
        for(ll j=1;j*j<=i;j++)
        {
            if(i%j==0) 
            {
                cnt++;
                if(i!=j*j) cnt++;
            }
        }
        v.push_back({cnt,i});
    }

    sort(v.begin(), v.end(), cmp);

    for(ll i=1;i<=t;i++)
    {
        ll n;
        cin>>n;
        cout<<"Case "<<i<<": "<<v[n-1].second<<endl;
    }
}