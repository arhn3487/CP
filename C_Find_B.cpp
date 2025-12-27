#include<bits/stdc++.h>
//#include "D:/debug.h"
using namespace std;

#define int long long
const int M=1e9+7;
//const ll infinity = LLONG_MAX;
int dx[]={1,0,-1,0,1,1,-1,-1};//Right,Down,Left,Up,Right-Up,Right-Down,Left-Up,Left-Down
int dy[]={0,-1,0,1,1,-1,1,-1};
//inline ll lcm(ll a,ll b) {return (a*b)/__gcd(a,b);}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin>>t;

    while(t--)
    {
        int n,q;
        cin>>n>>q;

        vector<int> v(n+10,0),one(n+10,0);

        for(int i=1;i<=n;i++)
        {
            cin>>v[i];
            one[i]= v[i]!=1 ? one[i-1] : one[i-1]+1;
            v[i]+=v[i-1];
        }

        // for(auto x : one) cout<<x<<" ";
        // cout<<endl;
        // for(auto x : v) cout<<x<<" ";
        // cout<<endl;

        while(q--)
        {
            int l,r;
            cin>>l>>r;

            if(l==r) cout<<"NO\n";
            else
            {
                //cout<<one[r]-one[l-1]<<" "<<+r-l+1<<" "<<v[r]-v[l-1]<<endl;
                int replaced_by_one=r-l+1-(one[r]-one[l-1]);
                int extra=v[r]-v[l-1]- replaced_by_one;
                //cout<<extra<<" "<<one[r]<<" "<<one[l-1]<<" "<<replaced_by_one<<endl;
                if(extra>=2*(r-l+1-replaced_by_one))cout<<"YES\n";
                else cout<<"NO\n";
            }
        }
    }
}