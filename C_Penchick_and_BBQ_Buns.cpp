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
        int n;
        cin>>n;

        if(n<8 || n%2) cout<<-1<<endl;
        else
        {
            int p=n/2;
            int q=sqrt(p);

            if(n%q==0)
            {
                //cout<<p<<" "<<q<<endl;
                q=q*q;
                int c=q+1,l=n/q;
                while(l--)
                {
                    for(int i=1;i<=q;i++) cout<<i<<" ";
                }
                cout<<endl;
            }
            else if(n%q==2)
            {
                int c=q+1,l=n/q;
                while(l--)
                {
                    for(int i=1;i<=q;i++) cout<<i<<" ";
                }
                cout<<n<<" "<<n<<endl;   
            }
            else cout<<-1<<endl;
        }
    }
}