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
        ll n,w,a,h=1;
        cin>>n>>w;
        ll left=w;
        deque<ll> v;

        for(ll i=0;i<n;i++)
        {
            cin>>a;
            v.push_back(a);
        }
        sort(v.begin(),v.end());
        //reverse(v.begin(),v.end());
        //for(auto x : v) cout<<x<<" ";
        //cout<<endl;
        while(!v.empty())
        {
            auto it = upper_bound(v.begin(),v.end(),left);
            if(it==v.begin())
            {
                h++;
                left=w;
            }
            else
            {
                it--;
                left-=*it;
                v.erase(it);
            }
        }
        cout<<h<<endl;
    }
}