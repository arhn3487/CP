#include<bits/stdc++.h>
//#include "D:/debug.h"
using namespace std;

#define ll long long
const int M=1e9+7;
const ll infinity = LLONG_MAX;
int dx[]={1,0,-1,0,1,1,-1,-1};//Right,Down,Left,Up,Right-Up,Right-Down,Left-Up,Left-Down
int dy[]={0,-1,0,1,1,-1,1,-1};
inline ll lcm(ll a,ll b) {return (a*b)/__gcd(a,b);}

#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
#define YES cout<<"YES\n";
#define NO cout<<"NO\n";

void solve()
{
    string str;
    cin>>str;
   // cout<<str<<endl;
    int l=str.length(),cntl=0,cntu=0;

    for(int i=l-1;i>=0;i--)
    {
        if(str[i]=='B') cntu++;
        else if(str[i]=='b') cntl++;
        else if(cntl && str[i]>='a'  && str[i]<='z')
        {
            str[i]='#';
            cntl--;
        }
        else if(cntu && str[i]>='A'  && str[i]<='Z')
        {
            str[i]='#';
            cntu--;
        }
        
    }

    for(int i=0;i<l;i++)
    {
        if(str[i]!='B' && str[i]!='b' && str[i]!='#') cout<<str[i];
    }
    cout<<'\n';
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t=1;
    cin>>t;

    for(int i=1;i<=t;i++)
    {
        //cout<<"Case "<<i<<": ";
        solve();
    }
}