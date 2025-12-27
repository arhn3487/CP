#include<bits/stdc++.h>
//#include "D:/debug.h"
using namespace std;

#define ll long long
const ll infinity = LLONG_MAX;
int dx[]={1,0,-1,0,1,1,-1,-1};
int dy[]={0,-1,0,1,1,-1,1,-1};
ll lcm(ll a,ll b) {return (a*b)/__gcd(a,b);}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    t=1;
    cin>>t;

    while(t--)
    {
        int n,c1=0,c0=0;
        cin>>n;

        string str,s2="";
        cin>>str;

        for(int i=0;i<n;i++)
        {
            if(str[i]=='0')
            {
                while(i<n && str[i]=='0') i++;
                i--;
            }
            s2.push_back(str[i]);
        }

        for(auto ch : s2)
        {
            if(ch=='0') c0++;
            else c1++;
        }

        if(c0<c1) cout<<"Yes\n";
        else cout<<"No\n";
    }
}