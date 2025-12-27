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

    for(int tc=1;tc<=t;tc++)
    {
        int n;
        ll sum=0;
        cin>>n;
        vector<int> v(n),v1(n);

        for(int i=0;i<n;i++) cin>>v[i];
        for(int i=0;i<n;i++) cin>>v1[i];

        sort(v.begin(),v.end());
        sort(v1.begin(),v1.end());

        for(int i=0;i<n;i++)
        {
            sum+=v[i]*v1[n-i-1];
        }

        cout<<"Case #"<<tc<<": "<<sum;
        if(tc!=n) cout<<"\n";
    }
}