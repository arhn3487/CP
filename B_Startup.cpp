#include<bits/stdc++.h>
//#include "D:/debug.h"
using namespace std;

#define ll long long
const int M=1e9+7;
const ll infinity = LLONG_MAX;
int dx[]={1,0,-1,0,1,1,-1,-1};//Right,Down,Left,Up,Right-Up,Right-Down,Left-Up,Left-Down
int dy[]={0,-1,0,1,1,-1,1,-1};
inline ll lcm(ll a,ll b) {return (a*b)/__gcd(a,b);}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin>>t;

    while(t--)
    {
        ll n,k,a,c,sum=0;
        cin>>n>>k;

        map<ll,ll> mp;

        for(int i=0;i<k;i++)
        {
            cin>>a>>c;
            mp[a]+=c;
        }

        vector<int> v;

        for(auto it=mp.begin();it!=mp.end();it++)
        {
            v.push_back(it->second);
        }

        sort(v.begin(),v.end());

        int sz=v.size();

        for(int i=sz-1;i>=0 && n;i--)
        {
            sum+=v[i];
            n--;
        }

        cout<<sum<<endl;
    }
}