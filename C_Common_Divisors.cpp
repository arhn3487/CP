#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,cnt=0;
    cin>>n;
    long long a,g=0;

    for(int i=0;i<n;i++)
    {
        cin>>a;
        g=__gcd(a,g);
    }

    for(long long i=1;i*i<=g;i++)
    {
        if(g%i==0)
        {
            cnt++;
            if(i*i!=g) cnt++;
        }
    }

    cout<<cnt<<'\n';
}