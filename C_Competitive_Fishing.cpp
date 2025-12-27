#include<bits/stdc++.h>
//#include "D:/debug.h"
using namespace std;

#define int long long
const int M=1e9+7;
//const ll infinity = LLONG_MAX;
int dx[]={1,0,-1,0,1,1,-1,-1};//Right,Down,Left,Up,Right-Up,Right-Down,Left-Up,Left-Down
int dy[]={0,-1,0,1,1,-1,1,-1};
//inline ll lcm(ll a,ll b) {return (a*b)/__gcd(a,b);}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin>>t;

    while(t--)
    {
        int n,k,m=0,sum=0,f=0;
        string str;
        cin>>n>>k>>str;
        vector<int> suf(n+1,0),res;

        for(int i=n-1;i>=0;i--)
        {
            if(str[i]=='1') suf[i]=suf[i+1]+1;
            else suf[i]=suf[i+1]-1; 
            if(suf[i]>0) res.push_back(suf[i]);
        }

        suf[0]=INT_MIN;

        sort(suf.rbegin(),suf.rend());

        // for(auto x : suf) cout<<x<<' ';
        // cout<<'\n';

        for(int i=0;i<n-1;i++)
        {
            sum+=suf[i];
            m++;
            if(sum>=k)
            {
                f=1;
                cout<<m+1<<endl;
                break;
            }
            
        }

        if(!f) cout<<-1<<endl;
    }
}