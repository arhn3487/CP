#include<bits/stdc++.h>
//#include "D:/debug.h"
using namespace std;

#define ll long long
const int M=1e9+7;



int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin>>t;

    while(t--)
    {
        string a,b;
        cin>>a>>b;
        int i=0;
        if(a.length()<b.length()) swap(a,b);
        int n=a.length(),m=b.length();
        //cout<<n<<" "<<m<<endl;

        while(i<n && a[i]==b[i])
        {
            i++;
        }

        //cout<<i<<" "<<m<<" "<<n<<endl;
        if(i) cout<<n+m-i+1<<endl;
        else cout<<n+m<<endl;
    }
}