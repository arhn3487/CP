#include<bits/stdc++.h>
//#include "D:/debug.h"
using namespace std;

#define ll long long
const ll infinity = LLONG_MAX;
int dx[]={1,0,-1,0,1,1,-1,-1};//Right,Down,Left,Up,Right-Up,Right-Down,Left-Up,Left-Down
int dy[]={0,-1,0,1,1,-1,1,-1};
ll lcm(ll a,ll b) {return (a*b)/__gcd(a,b);}

void op(char &ch,int delta)
{
    ch=char((ch-'0'+delta)%3+'0');
}

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
        int n,m;
        cin>>n>>m;
        vector<string> a(n),b(n);
        for(int i=0;i<n;i++) cin>>a[i];
        for(int i=0;i<n;i++) cin>>b[i];
        for(int i =0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(a[i][j]!=b[i][j])
                {
                    while(a[i][j]!=b[i][j])
                    {
                        op(a[i][j],1);
                        op(a[i+1][j+1],1);
                        op(a[i][j+1],2);
                        op(a[i+1][j],2);
                    }
                }
            }
        }
        if(a==b) cout<<"YES\n";
        else cout<<"NO\n";
    }
}