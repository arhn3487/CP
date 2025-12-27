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
        int n,k,res=1e9;
        cin>>n>>k;
        vector<int> v(n);

        for(int i=0;i<n;i++) cin>>v[i];

        for(int i=0;i<n;i++)//first
        {
            int p=v[i],f=1;
            res=i+1;
            for(int j=0;j<n;j++)//second
            {
                if(i==j) continue;
                int x=abs(v[i]-v[j]);
                if(x%k==0)
                {
                   //cout<<i<<" "<<j<<endl;
                    res=1e9;
                    break;
                }
                
            }
            if(res!=1e9) break;
        }

        if(res!=1e9) cout<<"YES\n"<<res<<'\n';
        else cout<<"NO\n";
    }
}