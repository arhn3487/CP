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
        ll n,m,cnt=0;
        char ch;
        cin>>n>>m;
        map<char,ll> mp;

        for(ll i=0;i<n;i++)
        {
            cin>>ch;
            mp[ch]++;
        }

        for(char i='A' ;i<='G';i++)
        {
            if(mp[i]<m) cnt+=m-mp[i];
        }
        cout<<cnt<<endl;
    }
}