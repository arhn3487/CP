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
        int n,a=0,b=0,c=0,d=0;
        string s;

        cin>>n>>s;
        
        for(int i=0;i<4*n;i++)
        {
            if(s[i]=='A') a++;
            else if(s[i]=='B') b++;
            else if(s[i]=='C') c++;
            else if(s[i]=='D') d++;
        }

        cout<<min(a,n)+min(b,n)+min(c,n)+min(d,n)<<endl;
    }
}