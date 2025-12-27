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
        int n,m,x,s=0;
        cin>>n>>m;
        vector<int> a(101,0),b(101,0);

        for(int i=1;i<=n;i++)
        {
            cin>>a[i];
        }
        for(int i=1;i<=m;i++) 
        {
            cin>>x;
            if(a[x]>0) a[x]--;
            else s++;
        }

        cout<<s<<endl;
    }
}