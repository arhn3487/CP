#include<bits/stdc++.h>
//#include "D:/debug.h"
using namespace std;

#define ll long long
const ll M=1e9+7;
const ll infinity = LLONG_MAX;
ll dx[]={1,0,-1,0,1,1,-1,-1};//Right,Down,Left,Up,Right-Up,Right-Down,Left-Up,Left-Down
ll dy[]={0,-1,0,1,1,-1,1,-1};
inline ll lcm(ll a,ll b) {return (a*b)/__gcd(a,b);}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll n,l,cnt=0;
    string str;

    cin>>n>>str;
    l=str.length();
    
    ll suf_zero[l+10]={0},pre_zero[l+10]={0};
    vector<ll> v;

    for(ll i=0;i<l;i++)
    {
        if(str[i]=='1') 
        {
            //cout<<i<<endl;
            v.push_back(i+1);
            suf_zero[i+1]=0;
        }
        else suf_zero[i+1]=suf_zero[i]+1;
    }

    if(n==0)
    {
        for(auto x : suf_zero) cnt+=x;
        cout<<cnt;
        return 0;
    }

    for(ll i=l-1;i>=0;i--)
    {
        if(str[i]=='1') 
            pre_zero[i+1]=0;
        else pre_zero[i+1]=pre_zero[i+2]+1;
    }
    
    //cout<<"arafat\n";

    // for(auto x : v) cout<<x<<" ";
    // cout<<endl;
    // for(auto x : suf_zero) cout<<x<<" ";
    // cout<<endl;
    // for(auto x : pre_zero) cout<<x<<" ";
    // cout<<endl;

    //cout<<n<<endl;

    for(ll i=0,j=n-1;j<v.size();i++,j++)
    {
        // cout<<"at\n";
        // cout<<i<<" "<<j<<" "<<v[i]-1<<endl;
        cnt++; 
        cnt+=suf_zero[v[i]-1];
        cnt+=pre_zero[v[j]+1];
        cnt+=suf_zero[v[i]-1]*pre_zero[v[j]+1];
    }

    cout<<cnt<<endl;
}