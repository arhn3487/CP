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
        ll n,sum=0,turn=1;;
        cin>>n;

        while(n)
        {
            if(n==4)
            {
                if(turn) 
                {
                    sum+=3;
                    break;
                }
                else n/=2;
            }
            if(n%2==0 && turn==1)
            {
                ll k=n/2;
                if(k%2)
                {
                    sum+=n/2;
                    n/=2;
                }
                else
                {
                    sum++;
                    n--;
                }
                turn =0;
            }
            else if(n%2 && turn==1)
            {
                sum++;
                n--;
                turn =0;
            }
            else if(n%2==0 && turn==0)
            {
                ll k=n/2;
                if(k%2)
                {

                    //sum+=n/2;
                    n/=2;
                }
                else
                {
                    //sum++;
                    n--;
                }
                turn =1;
            }
            else
            {
                //sum++;
                n--;
                turn =1;
            }

            //cerr<<(turn^1)<<" "<<sum<<" "<<n<<endl;
        }
        //cerr<<"\n";

        cout<<sum<<endl;
    }
}