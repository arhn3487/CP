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
        int n,a;
        cin>>n;
        vector<int> jor,bijor;

        for(int i=0;i<2*n;i++)
        {
            cin>>a;
            if(a%2) bijor.push_back(i+1);
            else jor.push_back(i+1);
        }

        int j=jor.size(),b=bijor.size(),sz=n-1;
        if(j%2) j--;
        if(b%2) b--;

        for(int i=0;i<j && sz;i+=2)
        {
            cout<<jor[i]<<" "<<jor[i+1]<<endl;
            sz--;
        }
        for(int i=0;i<b && sz;i+=2)
        {
            cout<<bijor[i]<<" "<<bijor[i+1]<<endl;
            sz--;
        }  
    }       
}