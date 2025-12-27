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
        int n,cf=0,cl=0;
        cin>>n;
        vector<int> v(n);
        for(int i=0;i<n;i++) cin>>v[i];

        if(v[0]!=v[n-1])
        {
            int i=0;
            while(i<n && v[0]==v[i]) 
            {
                cf++;
                i++;
            }
            //cf--;
            i=n-1;

            while(i>=0 && v[n-1]==v[i])
            {
                cl++;
                i--;
            }
            //cl--;
            //cout<<n<<" "<<cl<<" "<<cf<<endl;
            cout<<n-max(cl,cf)<<endl;
        }
        else
        {
            int i=0,j=n-1;
            while(i<n && v[0]==v[i]) 
            {
                cf++;
                i++;
            }
            i--;
            while(j>i && j>=0 && v[j]==v[n-1])
            {
                cl++;
                j--;
            }            
            
            cout<<n-cf-cl<<endl;
        }
    }
}