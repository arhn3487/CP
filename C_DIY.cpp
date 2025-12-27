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
        int n,l1=INT_MAX,l2=INT_MAX,h1=INT_MIN,h2=INT_MIN,x;
        cin>>n;

        map<int,int> mp;

        for(int i=0;i<n;i++)
        {
            cin>>x;
            mp[x]++;
        }

        auto it=mp.begin();

        while(it!=mp.end())
        {
            //cout<<it->first<<" "<<it->second<<endl;
            if(it->second>1)
            {
                if(l1==INT_MAX)
                {
                    l1=it->first;
                    it->second-=2;
                }
                if(l2==INT_MAX && it->second>1)
                {
                    l2=it->first;
                    it->second-=2;
                    break;
                }
                //if(it->second)
            }
            it++;
        }

        auto it2=mp.rbegin();

        while(it2!=mp.rend())
        {
            //cout<<it2->first<<" "<<it2->second<<endl;
            if(it2->second>1)
            {
                if(h1==INT_MIN)
                {
                    h1=it2->first;
                    it2->second-=2;
                }
                if(h2==INT_MIN && it2->second>1)
                {
                    h2=it2->first;
                    it2->second-=2;
                    break;
                }
            }
            it2++;
        }

        //cout<<l1<<" "<<l2<<" "<<h1<<" "<<h2<<" "<<l1<<" "<<h1<<" "<<l2<<" "<<h2<<endl;
        if(l1!=INT_MAX && l2!=INT_MAX && h1!=INT_MIN && h2!=INT_MIN) 
        {
            cout<<"YES\n";
            cout<<l1<<" "<<l2<<" "<<l1<<" "<<h1<<" "<<l2<<" "<<h1<<" "<<l2<<" "<<h1<<endl;
        }
        else cout<<"NO\n";
    }
}