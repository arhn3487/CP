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

string str;
int n;
ll ans=0;

void dfs(int index,ll sum_1st,ll sum_2nd)
{
    if(index==n)
    {
        sum_2nd=sum_2nd*10+str[index]-'0';
        sum_1st+=sum_2nd;
        ans+=sum_1st;
        //print(sum_1st)
        return;
    }

    sum_2nd=sum_2nd*10+str[index]-'0';
    dfs(index+1,sum_1st+sum_2nd,0);
    dfs(index+1,sum_1st,sum_2nd);
    
    // print("xxxxx")
    // print(sum_1st);
    // print(sum_2nd);
    
}

void solve()
{
    cin>>str;
    str='0'+str;
    n=str.length()-1;
    dfs(1,0,0);

    print(ans)
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t=1;
    //cin>>t;

    for(int i=1;i<=t;i++)
    {
        //cout<<"Case "<<i<<": ";
        solve();
    }
}