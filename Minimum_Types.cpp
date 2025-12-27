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
        ll n,k,cnt=0,sum=0;
        cin>>n>>k;
        vector<int> a(n),b(n);

        for(int i=0;i<n;i++) cin>>a[i];
        
        for(int i=0;i<n;i++)
        {
            cin>>b[i];
            b[i]*=a[i];
        }

        sort(b.rbegin(),b.rend());

        for(int i=0;i<n;i++)
        {
            cnt++;
            sum+=b[i];
            if(sum>=k)
            {
                break;
            }
        }

        if(sum>=k) cout<<cnt<<endl;
        else cout<<-1<<endl;
    }
}