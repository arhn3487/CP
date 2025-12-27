#include<bits/stdc++.h>
//#include "D:/debug.h"
using namespace std;

#define ll long long
const int M=1e9+7;
const ll infinity = LLONG_MAX;
int dx[]={1,0,-1,0,1,1,-1,-1};//Right,Down,Left,Up,Right-Up,Right-Down,Left-Up,Left-Down
int dy[]={0,-1,0,1,1,-1,1,-1};
inline ll lcm(ll a,ll b) {return (a*b)/__gcd(a,b);}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin>>t;

    while(t--)
    {
        int n,cnt=0;
        long long res=0;
        cin>>n;

        int arr[n][n];

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++) cin>>arr[i][j];
        }
        
        while(cnt<n)
        {
            cnt++;
            int i=0,j=n-cnt;
            int tmp=INT_MAX;

            while(i<cnt)
            {
                tmp=min(tmp,arr[i][j]);
                i++;
                j++;
            }

            //cout<<tmp<<endl;

            if(tmp<0) res+=abs(tmp);
            //res+=tmp;
        }

        cnt=0;
        while(cnt<n)
        {
            cnt++;
            int i=cnt,j=0;
            int tmp=INT_MAX;

            while(j<n-cnt)
            {
                tmp=min(tmp,arr[i][j]);
                i++;
                j++;
            }

            //cout<<tmp<<endl;

            if(tmp<0) res+=abs(tmp);
        }

        cout<<res<<endl;
    }
}