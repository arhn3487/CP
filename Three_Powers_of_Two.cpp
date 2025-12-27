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
        //vector<int> v;
        string str;
        cin>>str;
        int cnt=0;

        for(int i=0;i<n;i++)
            if(str[i]=='1')
            {
                cnt++;
                //v.push_back(i+1);
            }

        if(cnt>3) cout<<"NO\n";
        else if(str=="0" || str=="1" || str=="10") cout<<"NO\n";
        else cout<<"YES\n";
    }
}