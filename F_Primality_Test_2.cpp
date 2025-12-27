#include<bits/stdc++.h>
using namespace std;

#define ll long long

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    
        ll n,flag=1;
        cin>>n;
        if(n==1)
        {
            cout<<"No"<<endl;
            return 0;
        }

        for(int i=2;i*i<=n;i++)
        {
            if(n%i==0)
            {
                cout<<"No"<<endl;
                return 0;
            }
        }
        
        cout<<"Yes"<<endl;
}