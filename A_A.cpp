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
#define yes(x) cout << ((x) ? "YES\n" : "NO\n");

vector<int> lps; 
string txt,pat; 
int n,m;  
 
void lps_cal() 
{ 
    int i=1,len=0; 
     
    while(i<m) 
    { 
        if(pat[i]==pat[len]) 
        { 
            len++; 
            lps[i]=len; 
            i++; 
        } 
        else 
        { 
            if(len==0) i++; 
            else len=lps[len-1]; 
        } 
    } 
} 
 
int kmp() 
{ 
    m=pat.length(); 
    n=txt.length(); 
    lps.assign(m,0);
    lps_cal(); 
    int i=0,j=0; 
    vector<int> v; 
 
    while(i<n) 
    { 
        if(txt[i]==pat[j]) 
        { 
            i++; 
            j++; 
        } 
        else 
        { 
            if(j==0) i++; 
            else j=lps[j-1]; 
        } 
 
        if(j==m)  
        { 
            return i;
        } 
    } 
 
}

void solve()
{
    int n;cin>>n;
    m=4;
    cin>>txt;
    pat="code";

    int a=kmp();
    pat="chef";
    int b=kmp();

    if(a<b) cout<<"AC\n";
    else cout<<"WA\n";

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