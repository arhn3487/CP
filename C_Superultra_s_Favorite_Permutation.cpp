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

        if(n<5) cout<<-1<<endl;
        else if(n==5) cout<<"1 3 5 4 2\n";
        else
        {
            if(n%2==0)
            {
                for(int i=n;i>1;i-=2)
                {
                    if(i!=6) cout<<i<<" ";
                }
                cout<<6<<" 3 1 ";

                for(int i= 5 ;i<n;i+=2) cout<<i<<" ";
                cout<<endl;
            }

            else
            {
                n--;
                for(int i=n;i>1;i-=2)
                {
                    if(i!=6) cout<<i<<" ";
                }
                cout<<6<<" 3 1 ";

                for(int i= 5 ;i<n;i+=2) cout<<i<<" ";
                cout<<n+1<<endl;
            }
        
        }
    }
}