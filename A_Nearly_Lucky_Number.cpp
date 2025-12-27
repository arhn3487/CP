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

    string str;
    cin>>str;
    int l= str.length(),k=0;

    for(int i=0;i<l;i++)
    {
        if(str[i]=='7' || str[i]=='4') k++;
    }
    str=to_string(k);
    l=str.length();
    //cout<<str<<endl;
    for(int i=0;i<l;i++)
    {
        if(str[i]!='7' && str[i]!='4')
        {
            cout<<"NO\n";
            return 0;
        }
    }
    cout<<"YES\n";
}