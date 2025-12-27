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
        int n,k,cnt=0,p;
        cin>>n>>k;
        p=n;

      if(k>0)
      {
        k-=p;
        cnt++;
      }

       if(k>0)
       {
            for(int i=n-1;i>=1;i--)
            {
                if(k<=0) break;
                k-=i;
                cnt++;
                if(k>0)
                {
                    k-=i;
                    cnt++;
                }
            }
       }
        cout<<cnt<<endl;
    }
}