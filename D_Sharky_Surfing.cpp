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
        int n,m,L,u,v,ind=0,ans=0,pow=1,flag=1;
        cin>>n>>m>>L;
        priority_queue<pair<int,int>> pq;
        priority_queue<int> tmp; 
        vector<pair<int,int>> hr(n),pw(m);

        for(int i=0;i<n;i++)
        {
            cin>>u>>v;
            hr[i]={u,v};
        }
        for(int i=0;i<m;i++)
        {
            cin>>u>>v;
            pw[i]={u,v};
            pq.push({u,v});
        }

        //for(auto [a,b] : hr) cout<<a<<endl;

        for(auto [l,r] : hr)
        {
            while(ind<m && pw[ind].first<l)
            {
                //cout<<"arafat\n";
                tmp.push(pw[ind].second);
                pq.pop();
                ind++;
            }

            int dif=r-l+2;
            

            while(dif>pow && !tmp.empty())
            {
                // cout<<"AR\n";
                // cout<<dif<<" "<<pow<<endl;
                pow+=tmp.top();
                ans++;
                tmp.pop();
            }
            //cout<<dif<<" "<<pow<<endl;

            if(dif>pow)
            {
                flag=0;
                ans=-1;
                break;
            }
            //ind++;
        }

        cout<<ans<<endl;
    }
}