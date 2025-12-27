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
        ll n;
        cin>>n;
        vector<ll> v(n);
        set<ll> st;

        for(ll i=0;i<n;i++) 
        {
            cin>>v[i];
            st.insert(v[i]);
        }

        if(st.size()<2) cout<<"NO"<<endl;
        else{
            cout<<"YES"<<endl;
            //cout<<'R';
            //n--;
            for(ll i=0;i<n/2;i++)
            {
                cout<<'B';
            }
            cout<<'R';
            if(n%2==0) n--;
            for(ll i=0;i<n/2;i++)
            {
                cout<<'B';
            }
            cout<<endl;
        }
    }
}