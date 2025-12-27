#include<bits/stdc++.h>
using namespace std;

#define ll long long
const ll infinity = LLONG_MAX;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin>>t;

    while(t--)
    {
        ll n,tmp=1;
        cin>>n;
        map<ll,bool> mp;

        for(ll i=1;i<=n;i++) mp[i]=true;

        for(ll i=1;i<=n;i++)
        {
            cout<<tmp<<" ";
            mp.erase(tmp);
            tmp*=2;
            if(tmp>n) tmp=mp.begin()->first;
        }
        cout<<endl;
    }
}