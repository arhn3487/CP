#include<bits/stdc++.h>
//#include "D:/debug.h"
using namespace std;

#define ll long long
const int M=1e9+7;
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
    cin>>t;

    while(t--)
    {
        ll n,k,x,cnt=0;
        cin>>n>>k;
        while(n>0)
        {
            ll power =log(n)/log(k);
            int x=pow(k,power);
            cnt+=n/x;
            n%=x;
        }
        cout<<cnt<<endl;
        // if(k>n) cout<<n<<endl;
        
        // else cout<<x<<endl;
        //cout<<(log(a)/log(b))<<endl;
    }
}