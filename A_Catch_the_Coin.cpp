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
    t=1;
    cin>>t;

    while(t--)
    {
        int x,y;
        cin>>x>>y;
        if(x<0)
        {
            if(y>=-1) cout<<"YES\n";
            //else if(abs(x-y)<2) cout<<"YES\n";
            else cout<<"NO\n";
        }
        else{
            if(y>=-1) cout<<"YES\n";
            //else if(abs(x-y)<2) cout<<"YES\n";
            else cout<<"NO\n";
        }
    }
}