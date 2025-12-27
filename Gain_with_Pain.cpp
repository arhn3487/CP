#include<bits/stdc++.h>
//#include "D:/debug.h"
using namespace std;

#define ll long long
const int M=1e9+7;
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
    cin>>t;

    while(t--)
    {
        int day;
        bool consistent=true;
        cin>>day;

        for(int i=1;i<=day;i++)
        {
            int M,Q,R;
            for(int j=1;j<=5;j++)
            {
                cin>>M>>Q>>R;
                if(Q!=3 || R!=10) consistent=false;
                if(j<4 && M!=2) consistent=false;
                else if(j==4 && M!=1) consistent=false;
                else if(j==5 && M!=3) consistent=false;
            }
        }

        if(consistent) cout<<"Consistent\n";
        else cout<<"Inconsistent\n";
    }
}