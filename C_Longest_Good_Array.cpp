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
        int l,r;
        cin>>l>>r;
        int total=r-l;
        int i=1,cnt=1;

        while(l+i<=r)
        {
            l+=i;
            cnt++;
            i++;
            //cout<<l<<endl;
        }
        cout<<cnt<<endl;
    }

    //general furmula of 1+2+3+......+p==total find the value of p
 }