#include<bits/stdc++.h>
//#include "D:/debug.h"
using namespace std;

#define ll long long
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
    t=1;
    cin>>t;

    while(t--)
    {
        int n;
        cin>>n;
        string s;
        cin>>s;

        if(sqrt(n)*sqrt(n)!=n) cout<<"No\n";
        else 
        {
            int p = sqrt(n);
            s='0'+s;
            bool flag=true;
            for(int i=1;i<=p;i++)
            {
                for(int j=1;j<=p;j++)
                {
                    int a=(i-1)*p+j;
                    if(i==1 || j==p ||j==1 || i==p)
                    {
                        if(s[a]!='1')
                        {
                            flag=false;
                            break;
                        }
                    }
                    else
                    {
                        if(s[a]!='0')
                        {
                            flag=false;
                            break;
                        }
                    }
                }
            }

            if(flag) cout<<"Yes\n";
            else cout<<"No\n";
        }
    }
}