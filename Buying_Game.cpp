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
        int n,min_dif_created=INT_MAX,mni=-1;
        cin>>n;
        vector<pair<int,int>> v(n);

        for(int i=0;i<n;i++) cin>>v[i].first;
        for(int i=0;i<n;i++) cin>>v[i].second;
        vector<int> rem;

        ll cost=0;

        for(int i=0;i<n;i++)
        {
            if(v[i].first>=v[i].second)
            {
                cost+=v[i].second;
                if(v[i].first-v[i].second<min_dif_created)
                {
                    min_dif_created=v[i].first-v[i].second;
                    mni=i;
                }
            }
            else rem.push_back(i);
        }

        if(rem.size()==1) cost=min(cost+v[rem.back()].second,cost+v[rem.back()].first+min_dif_created);
        else for(auto x : rem) cost+=v[x].first;

        cout<<cost<<'\n';
    }
}