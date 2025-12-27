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
        int a,b,c,d,cnt=0;
        cin>>a>>b>>c>>d;
        vector<int> v(101,0);

        for(int i=a;i<=b;i++) v[i]++;
        for(int i=c;i<=d;i++) v[i]++;

        for(int i=1;i<=100;i++)
        {
            if((v[i]==2 && v[i-1]>0) || (v[i]==1 && v[i-1]>1)) cnt++;
        }

        if(cnt)cout<<cnt<<endl;
        else cout<<1<<endl;
    }
}