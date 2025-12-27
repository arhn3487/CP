#include<bits/stdc++.h>
using namespace std;

#define ll long long

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin>>t;

    while(t--)
    {
        ll n,k,q,d;
        cin>>n>>k>>q;
        vector<ll> a(k+1),b(k+1);
        a[0]=0;b[0]=0;

        for(ll i=1;i<=k;i++) cin>>a[i];
        for(ll i=1;i<=k;i++) cin>>b[i];

        while(q--)
        {
            cin>>d;
            if(d==0) {cout<<0<<" ";continue;}
            else if(d==n) {cout<<b[k]<<" ";continue;}

            auto it = upper_bound(a.begin(),a.end(),d)-a.begin();
            ll result=b[it-1];
            ll extra_dis=d-a[it-1];
            ll time=b[it]-b[it-1];
            ll dis=a[it]-a[it-1];
            
            //cout<<it<<" "<<extra_dis<<" "<<time<<" "<<dis<<endl;
            result+=(extra_dis*time)/dis;
            cout<<result<<" ";
        }
        cout<<endl;
    }
}