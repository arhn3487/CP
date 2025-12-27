#include<bits/stdc++.h>
#include "D:/debug.h"
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
        int n,k;
        cin>>n>>k;
        vector<vector<char>> v(n,vector<char>(n));
        
        for(int i =0;i<n;i++)
            for(int j=0;j<n;j++)
                cin>>v[i][j];

        for(int i=0;i<n;i+=k)
        {
            for(int j=0;j<n;j+=k){
                cout<<v[i][j];
            }
            cout<<endl;
        }
    }
}