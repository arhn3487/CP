#pragma GCC optimize("03")
#include<bits/stdc++.h>
#ifndef ONLINE_JUDGE
#include "D:/debug.h"
#else
#define dbg(x...)
#define dbgc(x...)
#endif
using namespace std;

#define ll long long
const int M=10010;
const ll infinity = LLONG_MAX;
int dx[]={1,0,-1,0,1,1,-1,-1};//Right,Down,Left,Up,Right-Up,Right-Down,Left-Up,Left-Down
int dy[]={0,-1,0,1,1,-1,1,-1};
inline ll lcm(ll a,ll b) {return (a*b)/__gcd(a,b);}

#define rall(v) v.rbegin(),v.rend()
#define all(v) v.begin(),v.end()
#define print(x) cout<<x<<'\n';
#define YES cout<<"YES\n";
#define NO cout<<"NO\n";

ll arr[10010];
bool is_prime[10010];
ll final_multiplication[M];
vector<int> prime;

void seive()
{
    memset(is_prime,true,M);
    is_prime[0]=is_prime[1]=false;

    for(int i=2;i<10010;i++)
    {
        if(is_prime[i])
            prime.push_back(i);
                for(int j=2*i;j<M;j+=i)
                    is_prime[j]=false;
    }
}

void prime_factorization(ll n)
{
    for(int i=0;prime[i]*prime[i]<=n &&i<prime.size();i++)
    {
        if(n%prime[i]==0)
        {
            ll cnt=1;
            while(n%prime[i]==0)
            {
                cnt*=prime[i];
                n/=prime[i];
            }
            final_multiplication[i]=max(cnt,final_multiplication[i]);
        }
    }
    if(n>1)
    {
        int pos=lower_bound(all(prime),n)-prime.begin();
        final_multiplication[pos]=max(final_multiplication[pos],n);
    }
}

string ansf(string a,ll b)
{
    ll carry=0,len=a.length();

    for(int i=0;i<len;i++)
    {
        carry+=(a[i]-'0')*b;
        a[i]=(carry%10)+'0';
        carry/=10;
    }

    while(carry>0)
    {
        a+=(carry%10)+'0';
        carry/=10;
    }

    return a;
}

void solve()
{
    memset(arr,0,sizeof(arr));
    memset(final_multiplication, 0, sizeof(final_multiplication)); 
    ll n,a,b;
    cin>>n;
    while(n--)
    {
        cin>>a;
        if(a>1) prime_factorization(a);
    }

    string ans="1";

    for(int i=0;i<prime.size();i++)
    {
        if(final_multiplication[i]) ans=ansf(ans,final_multiplication[i]);
    }
    reverse(all(ans));

    print(ans);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    seive();

    int t=1;
    cin>>t;

    for(int i=1;i<=t;i++)
    {
        cout<<"Case "<<i<<": ";
        solve();
    }
}