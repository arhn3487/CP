#include<bits/stdc++.h>
#include "D:/debug.h"
using namespace std;

#define ll long long
const ll infinity = LLONG_MAX;
int dx[]={1,0,-1,0,1,1,-1,-1};//Right,Down,Left,Up,Right-Up,Right-Down,Left-Up,Left-Down
int dy[]={0,-1,0,1,1,-1,1,-1};
ll lcm(ll a,ll b) {return (a*b)/__gcd(a,b);}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    t=1;
    cin>>t;

    while(t--)
    {
        ll n,k,s1=0,s2=0;
        cin>>n>>k;

        vector<ll> v(n);

        for(int i=0;i<n;i++) cin>>v[i];
        // if(n==1) 
        // {
        //     cout<<v[0]<<endl;
        //     continue;
        // }
        sort(v.begin(),v.end());

        for(int i=n-1;i>0;i-=2)
        {
            s1+=v[i];
            s2+=v[i-1];
            if(v[i-1]<v[i] && k>0)
            {
                ll dif=v[i]-v[i-1];
                if(dif<k)
                {
                    s2+=dif;
                    k-=dif;
                }
                else
                {
                    s2+=k;
                    k=0;
                }
            }
        }
        if(n%2) s1+=v[0];

        //cout<<s1<<" "<<s2<<endl;

        if(s2<s1) cout<<s1-s2<<endl;
        else cout<<0<<endl;
    }
}