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
        int n,a,b,x=0,y=0;
        bool f=false;
        string str;
        cin>>n>>a>>b>>str;
        
        for(int i=0;i<24*n;i++)
        {
            if(str[i%n]=='N') y++;
            else if(str[i%n]=='S') y--;
            else if(str[i%n]=='E') x++;
            else x--;

            if(x==a && y==b)
            {
                f=true;
                break;
            }
        }

        if(f) cout<<"YES\n";
        else cout<<"NO\n";
    }
}