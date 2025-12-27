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
        int n;
        ll sum=0;
        string str;
        cin>>n>>str;
        priority_queue<int> pq;

        int cnt=0;

        for(int i=n-1;i>=0;i--)
        {
            if(str[i]=='0')
            {
                if(!pq.empty())
                {
                    pq.pop();
                }
                //else pq.push(i+1);
                sum+=(i+1);
            }
            else pq.push(i+1);

            //cout<<sum<<" "<<pq.size()<<endl;
        }
        vector<int> v;
        while(!pq.empty())
        {
            v.push_back(pq.top());
            pq.pop();
        }

        sort(v.begin(),v.end());
        // for(auto x : v) cout<<x<<" ";
        // cout<<endl;

        int sz=v.size();
        //cout<<sz<<endl;

        if(sz%2) sz++;
        sz/=2;
        //cout<<sz<<endl;

        for(int i=0;i<sz;i++)
        {
            sum+=v[i];
        }

        cout<<sum<<endl;
    }
}