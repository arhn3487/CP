#include<bits/stdc++.h>
using namespace std;

#define ll long long
const ll infinity = LLONG_MAX;
int dx[]={1,0,-1,0,1,1,-1,-1};
int dy[]={0,-1,0,1,1,-1,1,-1};
ll lcm(ll a,ll b) {return (a*b)/__gcd(a,b);}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    t=1;
    cin>>t;

    while(t--)
    {
        int n;
        cin>>n;
        vector<int> v(n),f(n);

        for(int i=0;i<n;i++) cin>>v[i];
        f[n-1]=v[n-1];


        for(int i=n-2;i>=0;i--)
        {
            if(v[i]<=f[i+1])
            {
                f[i]=f[i+1]-v[i]+1+v[i];
            }
            else f[i]=v[i];
        }

        //for(auto it : f) cout<<it<<" ";
        //cout<<endl;

        cout<<f[0]<<endl;
    }
}
