#include<bits/stdc++.h>
//#include "D:/debug.h"
using namespace std;

#define ll long long
const int M=1e9+7;
const ll infinity = LLONG_MAX;
int dx[]={1,0,-1,0,1,1,-1,-1};//Right,Down,Left,Up,Right-Up,Right-Down,Left-Up,Left-Down
int dy[]={0,-1,0,1,1,-1,1,-1};
inline ll lcm(ll a,ll b) {return (a*b)/__gcd(a,b);}

#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
#define YES cout<<"YES\n";
#define NO cout<<"NO\n";

int cn=0;
set<array<array<int, 3>, 3>> x;

bool valid(int i,int j)
{
    return i<3 && i>=0 && j<3 && j>=0;
}

void dfs(array<array<int, 3>, 3> &v, int cnt)
{
    if(cnt==9)
    {
        int val=0;
        set<int> s;
        for(int i=0;i<3;i++)
        {
            for(int j=0;j<3;j++)
            {
                s.insert(v[i][j]);
            }
        }

        if(s.size()==9)
        {
            cn++;
            x.insert(v);
        } 
        return;
    }

    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            for(int k=0;k<8;k++)
            {
                int p=i+dx[k];
                int q=j+dy[k];

                if(!valid(p,q) || v[p][q] || v[i][j]==9) continue;

                v[p][q]=v[i][j]+1;
                dfs(v,cnt+1);
                v[p][q]=0;
            }
        }
    }
}

void solve()
{
    int a=0;
    array<array<int, 3>, 3> v = {};

    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
           char ch;
           cin>>ch;
           v[i][j]=ch-'0';
           if(v[i][j]) a++;
        }
    }

    array<array<int, 3>, 3> p = v;
    dfs(v,a);

    int k=0;

    for(const auto &u : x)
    {
        int f=0;
        for(int i=0;i<3;i++)
        {
            for(int j=0;j<3;j++)
            {
                for(int k=0;k<8;k++)
                {
                    int p=i+dx[k];
                    int q=j+dy[k];

                    if(valid(p,q) && u[p][q]==u[i][j]+1) 
                    {
                        f++;
                        break;
                    }
                }
            }
        }

        if(f==8) k++;
    }

    cout<<k<<endl;
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
