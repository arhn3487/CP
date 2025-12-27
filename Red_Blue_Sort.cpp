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
        int n,as=0,ds=0;
        bool f=false,sob_mile=true;
        cin>>n;
        vector<int> v(n);

        for(int i=0;i<n;i++)
        {
            cin>>v[i];
            if(v[i]==i+1) f=true;
            else sob_mile=false;
            //break;
        }

        if(sob_mile) cout<<n<<endl;
        else if(f) cout<<n-1<<endl;
        else cout<<n-2<<endl;
    }
}