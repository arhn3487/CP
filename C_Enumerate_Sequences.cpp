#include<bits/stdc++.h>
//#include "D:/debug.h"
using namespace std;

#define ll long long
const ll infinity = LLONG_MAX;
int dx[]={1,0,-1,0,1,1,-1,-1};//Right,Down,Left,Up,Right-Up,Right-Down,Left-Up,Left-Down
int dy[]={0,-1,0,1,1,-1,1,-1};
ll lcm(ll a,ll b) {return (a*b)/__gcd(a,b);}

int n,k;
vector<int> v;

void solve(int index,int sum,vector<int> &ds)
{
    if(index==n)
    {
        //int p=0;
        //for(int j=0;j<k;j++) cout<<ds[j]<<" ";
        //cout<<endl;
        if(sum%k==0)
        {
            for(int j=0;j<n;j++) cout<<ds[j]<<" ";
            cout<<endl;
        }
        return;
    }
    for(int i=1;i<=v[index];i++)
    {
        ds.push_back(i);
        solve(index+1,sum+i,ds);
        ds.pop_back();
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    t=1;
    //cin>>t;

    while(t--)
    {
        cin>>n>>k;
        v.resize(n);
        vector<int> x;

        for(int i=0;i<n;i++) cin>>v[i];

        solve(0,0,x);
    }
}