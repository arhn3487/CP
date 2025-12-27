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
    int arr[26]={};
    string str;
    //cin>>str;
    char c='a',k;

    while(cin>>k)
    {
        arr[k-'A']++;
    }

    // for(auto ch : str)
    // {
    //     arr[ch-'A']++;
    // }
    int p=0;

    for(int i=0;i<26;i++)
    {
        if(arr[i]%2) {p++;
        c=i+'A';}
        
    }
    if(p>1)
    {
        print("NO SOLUTION");
        return;
    }

    string res;
   // cout<<c<<'\n';
    if(c!='a')
    {
        for(int i=0;i<arr[c-'A'];i++) res+=c;
        arr[c-'A']=0;
    }

    for(int i=0;i<26;i++)
    {
        int p =arr[i];

        for(int j=0;j<p/2;j++) res+=char(i+'A');
        for(int j=0;j<p/2;j++) res=char(i+'A')+res;
    }
    cout<<res<<'\n';
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