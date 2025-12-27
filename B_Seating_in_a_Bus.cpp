#include<bits/stdc++.h>
//#include "D:/debug.h"
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin>>t;

    while(t--)
    {
        int n,a;
        cin>>n;
        bool flag=true;

        vector<int> v(n+1,0);
        cin>>a;
        v[a]=1;

        for(int i=1;i<n;i++)
        {
            cin>>a;
            if((a-1>0 &&v[a-1]==1) || (a+1<=n &&v[a+1]==1)) v[a]++;
            else flag=false;
        }

        if(flag) cout<<"YES\n";
        else cout<<"NO\n";
    }
}