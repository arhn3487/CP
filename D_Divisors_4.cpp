#include<bits/stdc++.h>
using namespace std;

#define ll long long

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin>>t;

    while(t--)
    {
        int n,cnt=0;
        cin>>n;
        //vector<ll> v;

        for(int i=1;i*i<=n;i++)
        {
            if(n%i==0)
            {
                i*i==n ? cnt+=1 : cnt+=2;
            }
        }
        cout<<cnt<<endl;
    }
}