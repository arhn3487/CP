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

    
        int n;
        bool f=true;
        cin>>n;
        vector<pair<int,int>>  v,v1;

        for(int i=0;i<n;i++)
        {
            string str;
            cin>>str;
            int l=str.length(),z=0;
            for(int j=0;j<l;j++)
                if(str[j]=='0') z++;
            
            v.push_back({z,l-z});
            v1.push_back({z,l-z});

            if(z!=0 && l-z!=0) f=false;
        }

        //for(auto x : v) cout<<x.first<<" "<<x.second<<endl;

        sort(v.begin(),v.end(),[&](pair<int,int> a,pair<int,int> b){
            //if(a.first==b.first) return a.second<b.second;
            return a.first>b.first;
        });
        sort(v1.begin(),v1.end(),[&](pair<int,int> a,pair<int,int> b){
            //if(a.first==b.first) return a.second<b.second;
            return a.second>b.second;
        });

        // for(auto x : v) cout<<x.first<<" "<<x.second<<endl;
        // cout<<endl;
        // for(auto x : v1) cout<<x.first<<" "<<x.second<<endl;
        

        ll s1=v[0].first,s2=v[0].second,sum1=v[0].second,sum2=v1[0].first;

        for(int i=1;i<n;i++)
        {
            sum1+=min(v[i].first,v[i].second);
            sum2+=min(v1[i].second,v1[i].first);
        }

        //cout<<sum2-v1[0].first<<" "<<sum1-v[0].second<<endl;

        if(f) cout<<0<<endl;
        else cout<<min(sum1,sum2)<<endl;
    
}