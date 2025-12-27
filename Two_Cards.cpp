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
        int n;
        cin>>n;
        vector<pair<int,int>> v(n);

        for(int i=0;i<n;i++) cin>>v[i].first;
        for(int i=0;i<n;i++) cin>>v[i].second;

        // sort(v.begin(),v.end()[&](pair<int,int>a,pair<int,int>b)
        // {
        //     return max(a.first,a.second)>max(b.first,b.second);
        // }
        // );

        sort(v.begin(), v.end(), [&](pair<int, int> a, pair<int, int> b) {
            int p=max(a.first, a.second);
            int q=max(b.first, b.second);
            if(p==q) return a.first>b.first;
            else return p>q;
        });

        int p=max(v[0].first,v[0].second),mx=-1,mxin=-1;

        for(int i=1;i<n;i++)
        {
            if(mx<v[i].first)
            {
                mx=v[i].first;
                mxin=i;
            }
        }

        int q=max(v[mxin].first,v[mxin].second);

        if(p>q) cout<<"Yes\n";
        else cout<<"No\n";
    }
}