#include<bits/stdc++.h>
//#include "D:/debug.h"
using namespace std;

#define ll long long
const int M=1e9+7;
const ll infinity = LLONG_MAX;
int dx[]={1,0,-1,0,1,1,-1,-1};//Right,Down,Left,Up,Right-Up,Right-Down,Left-Up,Left-Down
int dy[]={0,-1,0,1,1,-1,1,-1};
inline ll lcm(ll a,ll b) {return (a*b)/__gcd(a,b);}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin>>t;

    while(t--)
    {
        string str;
        cin>>str;
        int n=str.length();

        if(n<2) cout<<-1<<endl;
        else
        {
            bool f=false;
            for(int i=1;i<n;i++)
                if(str[i]==str[i-1])
                {
                    cout<<str[i]<<str[i]<<endl;
                    f=true;
                    break;
                }

            if(!f)
            {
                for(int i=2;i<n;i++)
                {
                    if(str[i]!=str[i-1] && str[i-1]!=str[i-2])
                    {
                        cout<<str[i-2]<<str[i-1]<<str[i]<<endl;
                        f=true;
                        break;
                    }
                }
            }
            if(!f) cout<<-1<<endl;
        }
    }
}