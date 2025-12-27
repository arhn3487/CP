#pragma GCC optimize("O3")
#include<bits/stdc++.h>
#ifndef ONLINE_JUDGE
#include "D:/debug.h"
#else
#define dbg(x...)
#define dbgc(x...)
#endif
using namespace std;

#define ll long long
const int M=1e9+7;
const ll infinity = LLONG_MAX;
int dx[]={1,0,-1,0,1,1,-1,-1};//Right,Down,Left,Up,Right-Up,Right-Down,Left-Up,Left-Down
int dy[]={0,-1,0,1,1,-1,1,-1};
inline ll lcm(ll a,ll b) {return (a*b)/__gcd(a,b);}

#define rall(v) v.rbegin(),v.rend()
#define all(v) v.begin(),v.end()
#define print(x) cout<<x<<'\n';
#define YES cout<<"YES\n";
#define NO cout<<"NO\n";

void solve()
{
    int n,op=0;
    string str,s="";
    cin>>n>>str;

    for(int i=0;i<n;i++)
    {
        if(str[i]=='1')
        {
            int j=i;
            while(j<n && str[j]!='0')
            {
                j++;
            }
            //int j=i;
            while(j<n && str[j]=='0')
            {
                j++;
            }
            j--;
            string ss="";
            for(int k=0;k<i;k++) ss+=str[k];
            for(int k=j;k>=i;k--)
            {
                ss+=str[k];
            }
            for(int k=j+1;k<n;k++) ss+=str[k];
            str=ss;
            break;
        }
    }

    //cout<<str<<endl;

    char state='0';
    for(int i=0;i<n;i++)
    {
        if(str[i]==state) op++;
        else
        {
            op+=2;
            if(state=='0') state='1';
            else state='0';
        }
    }

    cout<<op<<'\n';
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