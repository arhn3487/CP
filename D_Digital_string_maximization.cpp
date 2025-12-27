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
        string str;
        cin>>str;
        int l=str.length();
        vector<int> v(l);

        for(int i=0;i<l;i++) v[i]=str[i]-'0';

        for(int i=1;i<l;i++)
        {
            int j=i;
            while(j>0 && v[j]>v[j-1]+1)
            {
                v[j]--;
                swap(v[j],v[j-1]);
                j--;
            }
        }

        for(auto x : v) cout<<x;
        cout<<'\n';
    }
}