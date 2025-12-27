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
        int n,m;
        string str,r;
        cin>>n>>str>>r;
        m=n-1;

        int one=0,zero=0;
        bool f=true;

        for(int i=0;i<n;i++)
            if(str[i]=='0') zero++;
            else one++;
        
        for(int i=0;i<m;i++)
        {
            if(r[i]=='0' && one>0 && zero>0) one--;
            else if(r[i]=='1' && one>0 && zero>0)zero--;
            else
            {
                f=false;
                break;
            }
        }
            
        if(f) cout<<"YES\n";
        else cout<<"NO\n";
    }
}