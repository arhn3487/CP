#include<bits/stdc++.h>
#include "D:/debug.h"
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
        int n;
        cin>>n;
        //n--;
        vector<int> a(n),b(n-1);
        for(int i=0;i<n-1;i++) cin>>b[i];
        a[n-1]=b.back();
        a[0]=b[0];
        for(int i=n-2;i>0;i--)
        {
            a[i]=b[i]|b[i-1];
        }
        bool flag=false;

        for(int i=0;i<n-1;i++)
        {
            if(b[i]!=(a[i]&a[i+1]))
            {
                flag=true;
                break;
            }
        }

        //for(auto x : a) cout<<x<<" ";
        //cout<<"\n";

        if(flag) cout<<-1<<endl;
        else{
            for(auto c : a) cout<<c<<" ";
            cout<<endl;
        }
    }
}