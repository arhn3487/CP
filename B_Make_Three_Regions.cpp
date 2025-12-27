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
        int n,cnt=0;
        cin>>n;
        string s1,s2;
        cin>>s1>>s2;

        for(int i=1;i<n-1;i++)
        {
            if(s1[i+1]=='.' && s1[i-1]=='.' && s2[i]=='.' && s2[i+1]=='x' && s2[i-1]=='x') cnt++;
        }
        for(int i=1;i<n-1;i++)
        {
            if(s2[i+1]=='.' && s2[i-1]=='.' && s1[i]=='.' && s1[i+1]=='x' && s1[i-1]=='x') cnt++;
        }

        cout<<cnt<<endl;
    }
}