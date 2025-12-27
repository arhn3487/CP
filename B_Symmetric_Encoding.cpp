#include<bits/stdc++.h>
using namespace std;

#define ll long long

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin>>t;

    while(t--)
    {
        ll n;
        cin>>n;
        string str,res="",p;
        cin>>str;
        p=str;
        sort(str.begin(),str.end());
        auto last = unique(str.begin(),str.end());
        str.erase(last,str.end());
        //cout<<str<<endl;

        map<char,char> mp;
        int j=str.length()-1;
        for(int i=0;i<=j;i++)
        {
            mp[str[i]]=str[j];
            mp[str[j]]=str[i];
            j--;
        }

        /*for(auto p : mp)
        {
            cout<<p.first<<" "<<p.second<<endl;
        }*/
        for(int i=0;i<n;i++)
        {
            res.push_back(mp[p[i]]);
        }
        cout<<res<<endl;
    }
}