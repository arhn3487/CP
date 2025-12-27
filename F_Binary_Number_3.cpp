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
        ll n,z=0,o=0,op=0;
        cin>>n;
        string str;
        cin>>str;

        for(int i=0;i<n;i++)
            if(str[i]=='0') z++;

        int rem=n-z;

        // if(z==n && n!=1) 
        // {
        //     while(z--) cout<<0<<" ";
        //     cout<<endl;
        //     continue;
        // }
        
        for(int i=n-1;i>=0;i--)
        {
            
            if(str[i]=='0')
            {
                op+=o;
                cout<<op<<" ";
                z--;
            }
            else o++;
        }
        
        while(rem--) cout<<-1<<" ";
        cout<<endl;
    }
}