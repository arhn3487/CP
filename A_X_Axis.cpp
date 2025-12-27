#include<bits/stdc++.h>
using namespace std;

#define ll long long
const ll infinity = LLONG_MAX;
int dx[]={1,0,-1,0,1,1,-1,-1};
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
        int a,b,c,d,x1,x2,x3,i=0,r=1000;
        cin>>x1>>x2>>x3;

        for(i=0;i<20;i++)
        {
            int c=abs(x1-i)+abs(x2-i)+abs(x3-i);
            r=min(c,r);
            r=min(c,r);
        }
        cout<<r<<endl;
    }
}