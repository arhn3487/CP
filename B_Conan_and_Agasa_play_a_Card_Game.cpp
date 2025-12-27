#include<bits/stdc++.h>
using namespace std;

#define ll long long
const ll infinity = LLONG_MAX;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll n,a;
    cin>>n;
    map<ll,ll> mp;

    for(ll i=0;i<n;i++)
    {
        cin>>a;
        mp[a]++;
    }

    //auto it = mp.rbegin(),x=mp.rend();
    //ll tgt=it->second;

    for(auto it = mp.rbegin(); it != mp.rend(); ++it)
    {
        if(it->second % 2 == 1) 
        {
            cout<<"Conan"<<endl;
            return 0;
        }
    }

    //if(tgt%2) cout<<"Conan"<<endl;
    cout<<"Agasa"<<endl;
}