#pragma GCC optimize("O3")
#include<bits/stdc++.h>
#ifndef ONLINE_JUDGE
#else
#define debug(x...)
#endif
using namespace std;

#define ll long long
#define ld long double
#define int long long
const int M=1e9+7;
const int N=1e6+5;
const ll infinity = LLONG_MAX;
int dx[]={1,0,-1,0,1,1,-1,-1};//Right,Down,Left,Up,Right-Up,Right-Down,Left-Up,Left-Down
int dy[]={0,-1,0,1,1,-1,1,-1};
inline ll lcm(ll a,ll b) {return (a*b)/__gcd(a,b);}

#define rall(v) v.rbegin(),v.rend()
#define all(v) v.begin(),v.end()
#define print(x) cout<<x<<'\n';
#define yes(x) cout << ((x) ? "YES\n" : "NO\n");

string ch(string s)
{
    int i=s.length(),cnt=0;
    string res="";
    bool f=false;
    i--;
    while(i>=0)
    {
        char c = 'a'-'a'+39;
        if(s[i]>='0' && s[i]<='9') cnt++;
        ///char c="?"
        else f=true;
        if(cnt%3==1 && cnt!=1)
        {
            res=c+res;
        }
        res=s[i]+res;
        i--;
    }
    if(f) return s;
    return res;
    //debug(res);
}

void solve()
{
    string s;cin>>s;
    int n=s.length();
    string a,b,c;

    int i=0;
    while(s[i]!='=') {a.push_back(s[i]);i++;}
    i++;
    while(s[i]!='+') {b.push_back(s[i]);i++;}
    i++;
    while(i<n) {c.push_back(s[i]);i++;}
    
    //debug(a,b,c);
    cout<<a<<'='<<ch(b)<<'+'<<ch(c)<<'\n';
}

int32_t main()
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