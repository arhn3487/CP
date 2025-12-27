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

    for(int tc=1;tc<=t;tc++)
    {
        cout<<"Case "<<tc<<": ";
        int n,cnt=0;
        cin>>n;
        // for(int i=0;i<32;i++)
        //     if((n>>i)&1) cnt++;
        int x=log2(n);
        int l=1<<(x+1);
        //cout<<x<<endl;
        x=(1<<x);
        //cout<<x<<endl;
        
        if(x==n) cout<<l<<endl;
        else
        {
            //cout<<"arafat\n";
            string str="";

            while (n) {
                str = char((n & 1) + '0') + str;
                //cout<<str<<endl;
                n >>= 1;
            }

            str='0'+str;
            next_permutation(str.begin(),str.end());
            int p=0;
            int j=0;
            for(int i=str.length()-1;i>=0;i--)
            {
                if(str[i]=='1') p+=1<<j;
                j++;
                //cout<<p<<" "<<str<<endl;
            }
            cout<<p<<endl;
        }

    }
}