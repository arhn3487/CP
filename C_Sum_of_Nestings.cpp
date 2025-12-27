#include<bits/stdc++.h>
using namespace std;

#define ll long long
const ll infinity = LLONG_MAX;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll n,k,x,y;
    cin>>n>>k;

    y=1+sqrt(1+8*k);
    x=y/2;
    //cout<<x<<endl;
    //cout<<x*2<<" "<<y<<endl;

    if(k==0)
    {
        while(n--) cout<<"()";
        return 0;
    }

    if(x*2!=y) cout<<"Impossible"<<endl;
    else
    {
        for(int i=0;i<x;i++) cout<<'(';
        for(int i=0;i<x;i++) cout<<')';

        if(x<n)
        {
            int l = n-x;
            for(int i=0;i<l;i++) cout<<'(';
            for(int i=0;i<l;i++) cout<<')';
        }
    }
}