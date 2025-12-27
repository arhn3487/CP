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
    ll n,sz,ans=0,pow=1;
    string k;
    cin>>n>>k;
    sz=log10(n)+1;
    
    for(int i=k.length()-1;i>=0;)
    {
        string s="";
        ll len=1;
        s=k.substr(i,len);
        ll tmp=0;
        ll val=stoll(s);
        int it=0;

        while(val<n && it<sz)
        {
            tmp=val;
            i--;
            if(i<0) break;
            len++;
            s=k.substr(i,len);
            val=stoll(s);
            it++;
        }

        while(i<k.length()-1 && k[i+1]=='0' && tmp!=0) i++;
        if(tmp==0)
        {
            i+=(len-2);
        }
        ans+=(pow*tmp);
        pow*=n;
    }
    cout<<ans<<endl;
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