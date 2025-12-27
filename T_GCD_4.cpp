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

    for(int i=1;i<=t;i++)
    {
        ll ax,ay,bx,by;
        cin>>ax>>ay>>bx>>by;

        cout<<"Case "<<i<<": "<<__gcd(abs(ax-bx),abs(ay-by))+1<<endl;
    }
}