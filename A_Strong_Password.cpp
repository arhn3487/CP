#include<bits/stdc++.h>
//#include "D:/debug.h"
using namespace std;

#define ll long long
const ll infinity = LLONG_MAX;
int dx[]={1,0,-1,0,1,1,-1,-1};//Right,Down,Left,Up,Right-Up,Right-Down,Left-Up,Left-Down
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
        string a;
        cin>>a;
        int l=a.length();
        bool flag=true;

        for(int i=0;i<l-1;i++)
        {
            if(a[i]==a[i+1])
            {
                for(int j=0;j<=i;j++) cout<<a[j];
                if(a[i]=='z') cout<<char(a[i]-1);
                else cout<<char(a[i]+1);
                for(int j=i+1;j<l;j++)  cout<<a[j];
                cout<<endl;
                flag=false;
                break;
            }
        }
        if(flag)
        {
            cout<<a;
            if(a[l-1]=='z')cout<<char(a[l-1]-1)<<endl;
            else cout<<char(a[l-1]+1)<<endl;

        }
    }
}