#include<bits/stdc++.h>
//#include "D:/debug.h"
using namespace std;

#define ll long long
const ll infinity = LLONG_MAX;
int dx[]={1,0,-1,0,1,1,-1,-1};//Right,Down,Left,Up,Right-Up,Right-Down,Left-Up,Left-Down
int dy[]={0,-1,0,1,1,-1,1,-1};
ll lcm(ll a,ll b) {return (a*b)/__gcd(a,b);}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int h,w,q,a,b,cnt=0;
    cin>>h>>w>>q;
    vector<vector<bool>> v(h,vector<bool>(w,true));

    while(q--)
    {
        cin>>a>>b;
        a--;
        b--;
        if(v[a][b]) v[a][b]=false;
        else
        {
            int i=b;
            while(i>=0)
            {
                if(v[a][i])
                {
                    v[a][i]=false;
                    break;
                }
                i--;
            }
            i=b;
            while(i<w)
            {
                if(v[a][i])
                {
                    v[a][i]=false;
                    break;
                }
                i++;
            }
            i=a;
            while(i>=0)
            {
                if(v[i][b])
                {
                    v[i][b]=false;
                    break;
                }
                i--;
            }
            i=a;
            while(i<h)
            {
                if(v[i][b])
                {
                    v[i][b]=false;
                    break;
                }
                i++;
            }
        }
    }

    for(int i=0;i<h;i++)
    {
        for(int j=0;j<w;j++)
        {
            if(v[i][j]) cnt++;
        }
    }

    cout<<cnt<<endl;
}