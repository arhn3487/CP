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
        ll n,a,single=0,alice=0,bob=0,dbl=0,alice_point=0,bob_point=0;
        cin>>n;
        int arr[1001]={0};

        for(int i=0;i<n;i++)
        {
            cin>>a;
            arr[a]++;
        }

        for(int i=0;i<1002;i++)
        {
            if(arr[i]==1) single++;
            else if(arr[i]!=0)dbl++;
        }

        alice=(single+1)/2;
        alice_point=alice*2;
        bob=single-alice;
        bob_point*=bob;
        int baki_ase=n-single;

        //cout<<single<<" "<<dbl<<" "<<alice<<" "<<alice_point<<" "<<bob<<endl;

        if(single%2==0)//alice_turn
        {
            dbl*=2;
            ll p=dbl;
            ll q=(p+1)/2;
            alice_point+=q;
        }
        else //bob turn
        {
            dbl*=2;
            ll p=dbl;
            ll q=(p+1)/2;
            alice_point+=(p-q);
        }

        cout<<alice_point<<endl;
    }
}