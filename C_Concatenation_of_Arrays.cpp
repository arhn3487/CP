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

        for(int i=0;i<n;i++) cin>>v[i].first>>v[i].second;

        sort(v.begin(),v.end(),[&](pair<int,int> &a,pair<int,int>&b)
        {
            if(max(a.first,a.second)==max(b.first,b.second)) return min(a.first,a.second)<min(b.first,b.second);
            else return max(a.first,a.second)<max(b.first,b.second);
        });

        for(int i=0;i<n;i++) cout<<v[i].first<<" "<<v[i].second<<" ";
        cout<<endl;
    }
}