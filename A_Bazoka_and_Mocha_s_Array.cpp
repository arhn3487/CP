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
        ll n,flag=0,flag2=-0;
        cin>>n;
        vector<ll> v(n),s(n),a1,a2;

        for(ll i=0;i<n;i++) cin>>v[i];
        s=v;
        sort(s.begin(),s.end());

        if(s==v)
        {
            cout<<"Yes"<<endl;
            continue;
        }

        int i=0,j=0;
        while(i<n && v[i]<=v[i+1]) i++;
        i++;
        for(int k=i;k<n;k++)
        {
            a1.push_back(v[k]);
        }
        for(int k=0;k<i;k++)
        {
            a1.push_back(v[k]);
        }
        if(s==a1)
        {
            cout<<"Yes"<<endl;
            continue;
        }
        cout<<"No"<<endl;

    }
}