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
        ll n,p,q;
        //vector<ll> v();
        cin>>n;
        p=ceil(log(n));
        vector<char> v(p+1);
        v[p]='1';
        q=n-1LL<<p;
        bitset<32> l=q;
        string str=to_string(q);
        ll i=0;

        while(str[i]!='1' && i<32) i++;

        for(ll j=1;j<n;j++)
        {
            v[j]=str[i];
            i++;
        }

        for(ll j=1;j<=n;j++) cout<<v[j];
        cout<<endl;
    }
}