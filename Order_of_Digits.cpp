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

#define int ll

class Node
{
    public:
    int cnt;
    Node *child[10]={};
    Node()
    {
        cnt=0;
    }
};

Node *root=new Node();

void insert(string s)
{
    Node *cur=root;
    for(auto x : s)
    {
        int digit=x-'0';

        if(!cur->child[digit]) cur->child[digit]=new Node();
        cur=cur->child[digit];
        cur->cnt++;
    }
}

int count(string &s,vector<int> &order)
{
    int ans=0;
    Node *cur=root;
    for(char ch : s)
    {
        int digit=ch-'0';

        for(auto x : order)
        {
            if(x==digit) break;
            if(cur->child[x])
                ans+=cur->child[x]->cnt;
        }

        if(!cur->child[digit]) return ans;
        cur=cur->child[digit];
    }

    return ans;
}

void solve()
{
    int n,q;
    cin>>n;
    while(n--)
    {
        string s;cin>>s;
        reverse(all(s));
        while(s.size()<19) s.push_back('0');
        reverse(all(s));
        insert(s);
    }


    cin>>q;

    while ((q--))
    {
        vector<int> v(10);
        for(auto &x : v) cin>>x;
        string s;cin>>s;
        reverse(all(s));
        while(s.size()<19) s.push_back('0');
        reverse(all(s));
        cout<<count(s,v)<<'\n';
    }
    
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