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
        int n,mx=0,pos=-1;
        bool odd=false;
        cin>>n;

        vector<int> v(n);

        for(int i=0;i<n;i++) 
        {
            cin>>v[i];
            if(v[i]>mx)
            {
                mx=v[i];
            }
        }

        for(int i=0;i<n;i++)
        {
            if(v[i]==mx && i%2==0) odd=true;
        }

        if(n%2)
        {
            if(odd) cout<<n/2+1+mx<<endl;
            else cout<<n/2+mx<<endl;
        }
        else 
        {
            cout<<n/2+mx<<endl;
            //cout<<n/2+mx<<endl;
        }
    }
}
