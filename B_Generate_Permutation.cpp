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

        if(n%2==0) cout<<-1<<endl;
        else
        {
            vector<int> v(n);
            int p=n;

            for(int i=0;i<p/2;i++)
            {
                v[i]=n;
                v[p-i-1]=n-1;
                n-=2;
            }

            v[p/2]=1;

            for(int i=0;i<p;i++) cout<<v[i]<<" ";
            cout<<endl;
        }
    }
}