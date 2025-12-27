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
        int n,m,q,a;
        cin>>n>>m>>q;
        vector<int> v(m);

        for(int i=0;i<m;i++) cin>>v[i];
        sort(v.begin(),v.end());


        while(q--)
        {
            cin>>a;
            //cout<<a<<" "<<v[0]<<endl;
            
            //if(m==1) {cout<<abs(a-v[0])<<endl;continue;}

            if(a<v[0]) cout<<v[0]-1<<endl;
            else if(a>v[m-1]) cout<<n-v[m-1]<<endl;
            else
            {
                auto it=lower_bound(v.begin(),v.end(),a);
                auto jt=it-1;
                int md=(*it+*jt)/2;
                int t1=md-*jt,t2=*it-md;

                cout<<min(t1,t2)<<endl;
            }
        }
    }
}