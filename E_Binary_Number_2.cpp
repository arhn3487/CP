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
        ll n,res=0,p=1;
        cin>>n;
        vector<int> bin;

        cout<<"Case "<<tc<<": ";

        while(n)
        {
            if(n%2) bin.push_back(1);
            else bin.push_back(0);
            n/=2;
        }

        bin.push_back(0);
        reverse(bin.begin(),bin.end());

        next_permutation(bin.begin(),bin.end());

        for(int i=bin.size()-1;i>=0;i--)
        {
            if(bin[i]==1) res+=p;
            p*=2;
        }

        cout<<res<<endl;
    }
}