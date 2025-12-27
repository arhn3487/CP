#include<bits/stdc++.h>
//#include "D:/debug.h"
using namespace std;

#define ll long long
const int M=1e9+7;
const ll infinity = LLONG_MAX;
int dx[]={1,0,-1,0,1,1,-1,-1};//Right,Down,Left,Up,Right-Up,Right-Down,Left-Up,Left-Down
int dy[]={0,-1,0,1,1,-1,1,-1};
inline ll lcm(ll a,ll b) {return (a*b)/__gcd(a,b);}

bool ask(int i,int j)
{
    cout<<"? "<<i<<' '<<j<<endl;
    int k;
    cin>>k;
    return k==1;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin>>t;

    while(t--)
    {
        int n,ans=-1;
        cin>>n;

        for(int i=1;i+1<=n;i+=2)
        {
            if(ask(i,i+1)!=ask(i+1,i))
            {
                int j= i>1 ? 1 : i+2;

                if(ask(i,j)!=ask(j,i)) ans=i;
                else ans=i+1;
                break;

            }
        }
        if(ans==-1) ans=n;
        cout<<"! "<<ans<<endl;
    }
}