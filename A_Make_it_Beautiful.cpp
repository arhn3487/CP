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
        int n,s=0;
        bool f=true;
        cin>>n;
        vector<int> v(n);
        
        for(int i=0;i<n;i++) cin>>v[i];

        sort(v.begin(),v.end(),greater<int>());

        swap(v[1],v[n-1]);
        //cout<<v[n-1]<<' ';

        for(int i=0;i<n;i++)
        {
            if(v[i]==s)
            {
                f=false;
                break;
            }
            s+=v[i];
        }

        if(f)
        {
            cout<<"YES\n";
            for(auto x : v) cout<<x<<' ';
            cout<<'\n';
        }
        else cout<<"NO\n";
    }
}