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

    int t;
    t=1;
    cin>>t;

    while(t--)
    {
        int n,q;
        string a,b;
        cin>>n>>q>>a>>b;

        vector<vector<int>> freq_a(n,vector<int>(26,0));
        vector<vector<int>> freq_b(n,vector<int>(26,0));

        for(int i=0;i<n;i++)
        {
            if(i!=0) freq_a[i]=freq_a[i-1];
            if(i!=0) freq_b[i]=freq_b[i-1];

            freq_a[i][a[i]-'a']++;
            freq_b[i][b[i]-'a']++;
        }

        while(q--)
        {
            int l,r,cnt=0,cnt2=0,res=0;
            cin>>l>>r;
            l--;
            r--;
            
            for(int i=0;i<26;i++)
            {
                cnt=freq_a[r][i];
                if(l!=0) cnt-=freq_a[l-1][i];
                cnt2=freq_b[r][i];
                if(l!=0) cnt2-=freq_b[l-1][i];

                res+=abs(cnt-cnt2);
            }

            cout<<res/2<<endl;
        }
    }
}