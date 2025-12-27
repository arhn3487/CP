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
        int x,n;
        cin>>x>>n;

        vector<int> v;

        for(int i=1;i*i<=x;i++)
        {
            if(x%i==0) 
            {
                //cout<<i<<endl;
                v.push_back(i);
                if(i*i!=x)v.push_back(x/i);
            }
        }

        sort(v.begin(),v.end());

        // for(auto x : v) cout<<x<<' ';
        // cout<<'\n';
        int p =*lower_bound(v.begin(),v.end(),n);
        //cout<<p<<endl;
        cout<<x/p<<'\n';
    }
}