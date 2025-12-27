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
        ll n,c=INT_MAX,o=INT_MAX,move=0;
        cin>>n;
        ll candy[n],orange[n];

        for(int i=0;i<n;i++) 
        {
            cin>>candy[i];
            c=min(c,candy[i]);
        }
        for(int i=0;i<n;i++) 
        {
            cin>>orange[i];
            o=min(o,orange[i]);
        }

        for(int i=0;i<n;i++)
        {
            int flag=0,oo=0,cc=0;
            if(orange[i]>0)
            {
                flag=1;
                oo=orange[i]-o;
            }
            if(candy[i]>0)
            {
                flag=1;
                cc=candy[i]-c;
            }

            if(flag)
            {
                move+=max(cc,oo);
            }
        }

        cout<<move<<endl;

    }
}