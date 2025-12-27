#pragma GCC optimize("O3")
#include<bits/stdc++.h>
using namespace std;

#define ll long long
const int M=1e9+7;
const ll infinity = LLONG_MAX;
int dx[]={1,0,-1,0,1,1,-1,-1};
int dy[]={0,-1,0,1,1,-1,1,-1};
inline ll lcm(ll a,ll b) {return (a*b)/__gcd(a,b);}

#define rall(v) v.rbegin(),v.rend()
#define all(v) v.begin(),v.end()
#define print(x) cout<<x<<'\n';
#define YES cout<<"YES\n";
#define NO cout<<"NO\n";

int ask(int a,int b)
{
    cout<<"? "<<a<<" "<<b<<endl;
    cout.flush();
    int x;
    cin>>x;
    return x;
}

void solve()
{
    int n;
    cin>>n;
    vector<int> parent(n+1,-1);

    for(int i=2;i<=n;i++) 
    {
        int last = 1; 
        while(true)
        {
            int x = ask(i, last);
            if(x == i) break;
            last = x;
        }
        parent[i] = last;  
    }

    cout<<"! ";
    for(int i=2;i<=n;i++)
    {
        cout<<parent[i]<<" "<<i<<' ';
    }
    cout<<endl; 
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
        solve();
    }
}