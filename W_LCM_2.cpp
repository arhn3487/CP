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
        ll a,b;
        cin>>a>>b;
        if(a*2<=b) cout<<a<<" "<<a*2<<endl;
        else cout<<"-1 -1\n";
    }
}
