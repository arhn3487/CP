#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;

    while(t--)
    {
        int n,a,mx=-1;
        cin>>n;

        vector<int> v(1001,0);

        for(int i =0;i<n;i++) 
        {
            cin>>a;
            v[a]=i+1;
        }

        for(int i=1;i<=1000;i++)
        {
            for(int j =1;j<=1000;j++)
            {
                if(v[i] && v[j] && __gcd(i,j)==1)
                {
                    mx=max(mx,v[i]+v[j]);
                }
            }
        }

        cout<<mx<<endl;

    }
}