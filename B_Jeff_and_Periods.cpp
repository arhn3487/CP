#include<bits/stdc++.h>
using namespace std;

#define ll long long

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t,a,i,j=0,cnt=0;
    cin>>t;
    i=t;
    map<int,pair<int,int>>mp;
    vector<int> v(t);

    for(int i=0;i<t;i++) 
    {
        cin>>v[i];
    }

    for(int p=t-1;p>=0;p--)
    {
        if(mp[v[p]].second==0 && mp[v[p]].first==0)
        {
            mp[v[p]].first=p;
            cnt++;
        }
        else
        {
            mp[v[p]].second=mp[v[p]].first-p;
            mp[v[p]].first=p;
        }
    }

    cout<<cnt<<endl;
    for(auto num : mp) 
    {
        cout<<num.first<<" "<<num.second.second<<endl;
    }
}