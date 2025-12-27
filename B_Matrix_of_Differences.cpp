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
        int n;
        cin>>n;
        int mx=n*n,mn=1;
        int arr[n+1][n+1];

        for(int i=0;i<n;i++)
        {
            if(i%2==0)
            {
                for(int j=0;j<n;j++)
                {
                    if(j%2==0) arr[i][j]=mn++;
                    else arr[i][j]=mx--;
                }
            }
            else
            {
                for(int j=n-1;j>=0;j--)
                {
                    if(j%2==0) arr[i][j]=mx--;
                    else arr[i][j]=mn++;
                }
            }
        }

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++) cout<<arr[i][j]<<' ';
            cout<<'\n';
        }
    }
}