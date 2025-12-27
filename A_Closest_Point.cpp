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
        int n,a;
        cin>>n;
        map<int,int> mp;

        for(int i=0;i<n;i++)
        {
            cin>>a;
            mp[a]++;
        }

        if(mp.size()==1) cout<<"YES\n";
        else if(mp.size()==2)
        {
            auto it=mp.begin();
            
            auto it2=--mp.end();
            //cout<<it->first<<" "<<it2->first<<endl;
            if(abs(it->first-it2->first)>1)cout<<"YES\n";
            else cout<<"NO\n";
        }
        else cout<<"NO\n";
    }
}