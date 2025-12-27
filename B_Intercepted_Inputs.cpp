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
        int k;
        cin>>k;
        int n=k-2;
        vector<int> v(k);

        for(int i=0;i<k;i++) cin>>v[i];

        sort(v.begin(),v.end());

        for(int i=0;i<k;i++)
        {
            if(n%v[i]==0)
            {
                int l=n/v[i];
                auto it = lower_bound(v.begin(),v.end(),l);
                int q=it-v.begin();
                if(it!=v.end() && i!=q && v[i]**it==n)
                {
                    cout<<v[i]<<" "<<*it<<endl;
                    break;
                }
            }
        }
    }
}