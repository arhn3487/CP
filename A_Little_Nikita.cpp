#include<bits/stdc++.h>
using namespace std;

#define ll long long
const ll infinity = LLONG_MAX;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin>>t;

    while(t--)
    {
        ll n,m,e;
        cin>>n>>m;
        e=n-m;
        if(m>n) cout<<"No"<<endl;
        else if(n==m) cout<<"Yes"<<endl;
        else if(e%2==0) cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }
}