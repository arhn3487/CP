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
        int a,b;
        cin>>a>>b;
        if(a==b) cout<<0<<endl;
        else if(a<b)
        {
            int k=b-a;
            int l=k/2;
            if(k%2) cout<<1<<endl;
            else if(l%2==1 && l*2==k) cout<<2<<endl;
            else cout<<3<<endl;
        }
        else
        {
            int k=a-b;
            int l=k/2;
            if(k%2==0) cout<<1<<endl;
            //else if(l%2==1 && l*2==k) cout<<2<<endl;
            else cout<<2<<endl;
        }
    }
}