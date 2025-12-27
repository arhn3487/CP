#include<bits/stdc++.h>
//#include "D:/debug.h"
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
    string str;
    cin>>str;
    vector<pair<string,pair<int,int>>> v;
    int n=str.length(),fz=0;

    while(fz<n && str[fz]=='1') fz++;
    
    int len=n-fz;

    if(len==0)
    {
        cout<<"1 1 1 "<<n<<'\n';
        return;
    }

    for(int i=0;i<fz;i++)
    {
        string ans="";
        for(int j=0;j<len;j++)
        {
            if(str[i+j]==str[j+fz]) ans+='0';
            else ans+='1';
        }
        v.push_back({ans,{i+1,i+len}});
    }

    auto it=max_element(all(v));

    cout<<1<<" "<<n<<' '<<it->second.first<<" "<<it->second.second<<'\n';
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