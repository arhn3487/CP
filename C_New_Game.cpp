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
        int n,k,cnt=0;
        cin>>n>>k;
        vector<int> v(n);

        for(int i=0;i<n;i++) cin>>v[i];

        sort(v.begin(),v.end());

        for(int l=0,r=0;l<n;l++)
        {
            while(l>r) r++;
            while(r+1<n && v[r+1]-v[r]<2 && v[r+1]-v[l]<k) r++;
            cnt=max(cnt,r-l+1);
        }
        cout<<cnt<<endl;
    }
}