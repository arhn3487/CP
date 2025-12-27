#include<bits/stdc++.h>
using namespace std;

#define ll long long
const ll infinity = LLONG_MAX;
int dx[]={1,0,-1,0,1,1,-1,-1}; // Not used
int dy[]={0,-1,0,1,1,-1,1,-1}; // Not used
ll lcm(ll a,ll b) {return (a*b)/__gcd(a,b);}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;

    while(t--)
    {
        double x,y,k,a,b,cnt;
        cin>>x>>y>>k;

        //cout<<x<<" "<<y<<endl;

        //cout<<ceil(x/k)<<endl;

        if(x>y) cnt=(2*(ceil(x/k)))-1;
        else cnt=(2*(ceil(y/k)));

        cout<<cnt<<endl;
    }
}
