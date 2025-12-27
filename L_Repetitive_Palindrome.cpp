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
    ll n,m;
    bool flag=false;
    cin>>str>>n;
    set<char> st;
    m=str.length();

    for(auto x : str)
    {
        st.insert(x);
        if(st.size()>1) break;
    }

    for(int i=0;i<str.length()/2;i++)
    {
        if(str[i]!=str[m-i-1]) 
        {
            flag=true;
            break;
        }
    }
    if(flag) cout<<"NO\n";
    else cout<<"YES\n";
}