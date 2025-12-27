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
        ll n,flag=1;
        cin>>n;

        for(int i=2;i*i<=n;i++)
        {
            if(n%i==0)flag=0;
        }
        
        if(n==1) cout<<"No"<<endl;
        else if(flag) cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }
}