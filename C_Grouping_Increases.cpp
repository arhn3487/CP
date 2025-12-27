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
        int n,x,cnt=0;
        cin>>n;
        vector<int> v1,v2,v(n);

        for(int i=0;i<n;i++) cin>>v[i];

        v1.push_back(v[0]);

        for(int i=1;i<n;i++)
        {
            if(v1.size() && v2.size())
            {
                if(v[i]<=v1.back() && v[i]<=v2.back())
                {
                    if(v1.back()<v2.back()) v1.push_back(v[i]);
                    else v2.push_back(v[i]);
                }
                else if(v[i]<=v1.back()) v1.push_back(v[i]);
                else if(v[i]<=v2.back()) v2.push_back(v[i]);
                else
                {
                    if(v1.back()<v2.back()) v1.push_back(v[i]);
                    else v2.push_back(v[i]);
                    cnt++;
                }
            }
            else
            {
                if(v1.back()==v[i]) v1.push_back(v[i]);
                else if(v1.back()<v[i]) v2.push_back(v[i]);
                else v1.push_back(v[i]);
            }
        }

        // for(auto p : v1) cout<<p<<" ";
        // cout<<endl;
        // for(auto p : v2) cout<<p<<" ";
        // cout<<endl;

        // for(int i=1;i<v1.size();i++)
        //     if(v1[i]>v1[i-1]) cnt++;

        // for(int i=1;i<v2.size();i++) 
        //     if(v2[i]>v2[i-1]) cnt++;

        cout<<cnt<<endl;
    }
}