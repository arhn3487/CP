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
        ll n,a;
        cin>>n;

        vector<ll> even,odd;

        for(int i=0;i<n;i++)
        {
            cin>>a;
            if(a%2) odd.push_back(a);
            else even.push_back(a);
        }

        if(even.size()==0 || odd.size()==0) cout<<0<<endl;
        else
        {
            sort(even.begin(),even.end());
            sort(odd.begin(),odd.end());
            bool flag=true;
            ll tmp=odd.back();
            for(auto e : even)
            {
                //cout<<tmp<<" "<<e<<endl;
                if(e>tmp)
                {
                    flag=false;
                    break;
                }

                tmp+=e;
            }

            if(flag) cout<<even.size()<<endl;
            else cout<<even.size()+1<<endl;
        }
    }
}