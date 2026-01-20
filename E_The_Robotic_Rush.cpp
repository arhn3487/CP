#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#ifndef ONLINE_JUDGE
#include "D:/debug.h"
#else
#define debug(x...)
#endif
using namespace std;

#define ll long long
#define ld long double
#define int long long
const int M = 1e9 + 7;
const int N = 1e6 + 5;
const ll infinity = LLONG_MAX;
int dx[] = {1, 0, -1, 0, 1, 1, -1, -1}; //Right, Down, Left, Up, Diagonals
int dy[] = {0, -1, 0, 1, 1, -1, 1, -1};
inline ll lcm(ll a, ll b) { return (a * b) / __gcd(a, b); }

#define rall(v) v.rbegin(), v.rend()
#define all(v) v.begin(), v.end()
#define print(x) cout << x << '\n';
#define yes(x) cout << ((x) ? "YES\n" : "NO\n");

void solve() 
{
    int n,m,k;cin>>n>>m>>k;
    vector<array<int,3>> v(n);
    vector<int>b(m);
    
    for(int i=0;i<n;i++) cin>>v[i][0];
    for(int i=0;i<m;i++) cin>>b[i];
    string s;cin>>s;
    int l=s.length();
    vector<int> neg(l),pos(l),ind(l);
    map<int,int> morbe;
    // neg[0]=(s[0]=='L') : -1 : 0;
    // pos[0]==(s[0]=='R') : 1 : 0;
    ind[0]==(s[0]=='L') ? -1 : 1;

    for(int i=1;i<l;i++)
    {
        int add=(s[i]=='L') ? -1 : 1;
        ind[i]+=ind[i-1]+add;
    }

    neg[0]=(ind[0]==-1) ? -1 : 0;
    pos[0]=(ind[0]==1) ? 1 : 0;

    for(int i=1;i<n;i++)
    {
        neg[i]=min(neg[i-1],ind[i]);
        pos[i]=max(pos[i-1],ind[i]);
    }
   
    for(int i=0;i<n;i++)
    {
        auto it=lower_bound(all(b),v[i][0]);
        if(it==b.end())it--;
        v[i][2]=(*it-v[i][0]);
        
        int kk=(it==b.begin()) ? 1 : -1;
        if(kk==-1) it--;
        if(kk==1) v[i][1]=-1e12 ;
        else v[i][1]=v[i][0]-*it;
    }

    for(int i=0;i<n;i++)
    {
        int mm=min(lower_bound(all(pos),v[i][2])-pos.begin(),*lower_bound(all(neg),v[i][1])-neg.begin())
        morbe[mn]+=1;
    }

    for(int i=0;i<l;i++)
    {
        cout<<morbe[i]<<' ';
    }
    cout<<'\n';
    for(int i=0;i<n;i++)
    {
        cerr<<i<<" -> ";
        for(int j=0;j<3;j++)
        {
            cerr<<v[i][j]<<' ';
        }
        cerr<<'\n';
    }
    //debug(v);

    
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t = 1;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        // cout << "Case " << i << ": ";
        solve();
    }
    return 0;
}