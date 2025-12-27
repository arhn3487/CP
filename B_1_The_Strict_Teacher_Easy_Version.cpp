#include<bits/stdc++.h>
//#include "D:/debug.h"
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
    cin>>t;

    while(t--)
    {
        int n,m,q,d;
        cin>>n>>m>>q;

        vector<int> v(m);

        for(int i=0;i<m;i++) cin>>v[i];
        sort(v.begin(),v.end());

        cin>>d;

        if(d<=v[0]) cout<<v[0]-1<<endl;
        else if(d>=v[1]) cout<<n-v[1]<<endl;
        else
        {
            int md=(v[0]+v[1])/2;
            int t1=md-v[0];
            int t2=v[1]-md;

            cout<<min(t1,t2)<<endl;
        }
    }
}