#include<bits/stdc++.h>
using namespace std;

#define ll long long
const ll infinity = LLONG_MAX;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    double n,k,x,y,tx,ty;
    double total=0;
    cin>>n>>k>>x>>y;
    n--;
    while(n--)
    {
        cin>>tx>>ty;
        total+=sqrt(abs(tx-x)*abs(tx-x)+abs(ty-y)*abs(ty-y));
        //cout<<total<<endl;
        x=tx,y=ty;
    }
    cout<<fixed<<setprecision(9)<<total*k/50.0<<endl;
}