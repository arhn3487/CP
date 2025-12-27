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
    //t=1;

    while(t--)
    {
        ll x,y,k;
        cin>>x>>y>>k;

        while(k--)
        {
            x++;
            if(x%y==0)
            {
                while(x%y==0) x/=y;
            }
        }
        cout<<x<<endl;
    }
}