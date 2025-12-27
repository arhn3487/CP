#include<bits/stdc++.h>
//#include "D:/debug.h"
using namespace std;

#define ll long long
const int M=1e9+7;
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
        int n,k,extra=0,cnt=0;
        cin>>n>>k;

        vector<int> v(n);

        for(int i=0;i<n;i++) cin>>v[i];
        //for(auto x : v) cout<<x<<" ";

        for(int i=0;i<n;i++)
        {
            if(v[i]>=k) extra+=v[i];
            if(v[i]==0)
            {
                if(extra>0) 
                {
                    extra-=1;
                    cnt++;
                }
            }
            //cout<<i<<" "<<v[i]<<" "<<extra<<endl;
        }

        cout<<cnt<<endl;
    }
}