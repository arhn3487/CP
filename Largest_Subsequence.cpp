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
        ll n,max_a=-1,min_a=infinity,max_b=-1,min_b=infinity;
        cin>>n;

        string str;
        cin>>str;

        for(ll i=0;i<n;i++)
        {
            if(str[i]=='a')
            {
                max_a=max(max_a,i);
                min_a=min(min_a,i);
            }
            else
            {
                max_b=max(max_b,i);
                min_b=min(min_b,i);
            }
        }

        cout<<max(max_a-min_a+1,max_b-min_b+1)<<endl;
    }
}