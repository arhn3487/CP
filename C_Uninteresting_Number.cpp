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
        string str;
        bool f=false;
        cin>>str;
        int l=str.length();
        ll sum=0,two=0,three=0;

        for(int i=0;i<l;i++)
        {
            sum+=(str[i]-'0')%9;
            if(str[i]-'0'==2) two++;
            else if(str[i]-'0'==3) three++;
        }

        for(int i=0;i<=two;i++)
        {
            for(int j=0;j<=three;j++)
            {
                if((sum+i*2+j*6)%9==0)
                {
                    f=true;
                    break;
                }
            }
        }

        if(f) cout<<"YES\n";
        else cout<<"NO\n";
    }
}