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
        char ch;
        ll num,lcm=1;
        vector<ll> v;
        while(cin>>num)
        {
            cin>>ch;
            v.push_back(num);
            if(ch=='\n') break;
        }

        ll l =v.size();

        for(ll i=0;i<l;i++)
        {
            lcm=(__gcd(v[i],lcm))/(lcm*v[i]);
        }

        cout<<lcm<<endl;
    }
}