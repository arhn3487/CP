#include<bits/stdc++.h>
using namespace std;

int main()
{
    long long a,b,c,cnt=0;
    cin>>a>>b>>c;

    for(long long i=1;i<=c;i++)
    {
        if(c%i==0 && i>=a && i<=b) cnt++;
    }
    cout<<cnt<<endl;
}
