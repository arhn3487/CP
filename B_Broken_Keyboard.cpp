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
        int n,i=0;
        string str;
        cin>>n>>str;
        vector<char> v1,v2;

        while(i<n)
        {
            v1.push_back(str[i]);
            i++;
            if(i<n) v2.push_back(str[i]);
            i++;
            if(i<n) v2.push_back(str[i]);
            i++;
        }

        if(v2.size()%2) cout<<"NO\n";
        else
        {
            // cout<<"ARAFAT\n";
            // for(auto x : v2) cout<<x<<" ";
            bool f=false;
            for(int i=0;i<v2.size();i+=2)
            {
                if(v2[i]!=v2[i+1]) f=true;
            }

            if(f) cout<<"NO\n";
            else cout<<"YES\n";
        } 
    }
}