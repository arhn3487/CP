#pragma GCC optimize("O3")
#include<bits/stdc++.h>
#ifndef ONLINE_JUDGE
#include "D:/debug.h"
#else
#define debug(x...)
#endif
using namespace std;
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define nl "\n"
#define ends " "
#define line cout << "\n";
#define space cout << " ";
#define End return 0
#define ll long long
#define db double
#define all(arr) arr.begin(),arr.end()
#define rall(arr) arr.rbegin(),arr.rend()
#define loop(a,b) for(auto i=(a);i<=(b);i++)
#define rloop(a,b) for(auto i=(a);i>=(b);i--)
#define Loop(i,a,b) for(auto (i)=(a);(i)<=(b);(i)++)
#define rLoop(i,a,b) for(auto (i)=(a);(i)>=(b);(i)--)
#define Iterate(i,x) for(auto (i)=(x).begin();(i)!=(x).end();(i)++)
#define rIterate(i,x) for(auto (i)=(x).rbegin();(i)!=(x).rend();(i)++)
#define YES cout << "YES\n"
#define NO cout << "NO\n"
#define Yes cout << "Yes\n"
#define No cout << "No\n"
#define yes cout << "yes\n"
#define no cout << "no\n"
#define fileio freopen("input.txt","r",stdin);freopen("output.txt","w",stdout)
int dx[] = {-1,1,0,0};
int dy[] = {0,0,-1,1};

void solve()
{
    ll k,a;
    cin >> k >> a;
    ll flag = 1LL<<k;
    ll b = (flag<<1)-a;
    stack<int>st;
    while(a!=flag)
    {
        if(a<b)
        {
            st.push(1);
            b-=a;
            a<<=1;
        }
        else
        {
            st.push(2);
            a-=b;
            b<<=1;
        }
    }
    cout << st.size() << "\n";
    while(!st.empty())
    {
        cout << st.top() << " ";
        st.pop();
    }
    line;
}

signed main()
{
    fast;
    int t=1;
    cin >> t;
    loop(1,t)
    {
        //cout << "Case " << i << ": ";
        //cout << "Case #" << i << ": ";
        //cout << "Case " << i << ":\n";
        solve();
        //line;
    }
    End;
}