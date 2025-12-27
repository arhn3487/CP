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

    for(ll i=1;i<=t;i++)
    {
        ll p,l,r;
        cin>>p>>l;
        r=p-l;
        vector<ll> v;

        for(ll c=1;c*c<=r;c++)
        {
            if(r%c==0 && l*c<r)
            {
                v.push_back(r/c);
                if(c*c!=r && l<c) v.push_back(c);
            }
        }

        cout<<"Case "<<i<<": ";
        if(v.size()==0)
        {
            cout<<"impossible"<<endl;
            continue;
        }

        sort(v.begin(),v.end());

        for(auto n : v) cout<<n<<" ";
        cout<<endl;
    }
}