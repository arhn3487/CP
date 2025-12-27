#include<bits/stdc++.h>
using namespace std;

#define ll long long
const ll infinity = LLONG_MAX;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin>>t;

    while(t--)
    {
        int a,b;
        string str;
        cin>>a>>b;
        cin>>str;
        map<char,int> mp;

        for(char ch : str)
        {
            mp[ch]++;
        }

        /*for(auto num : mp)
        {
            cout<<num.first<<" "<<num.second<<endl;
        }*/
        

        if(a==0 && b==0) cout<<"YES"<<endl;
        else if(a>=0 && b>=0)
        {
            if(mp['R']>=a && mp['U']>=b) cout<<"YES"<<endl;
            else cout<<"NO"<<endl;
        }
        else if(a<=0 && b>=0)
        {
            //cout<<"ar"<<endl;
            if(mp['L']>=-a && mp['U']>=b) cout<<"YES"<<endl;
            else cout<<"NO"<<endl;
        }
        else if(a<=0 && b<=0)
        {
            if(mp['L']>=-a && mp['D']>=-b) cout<<"YES"<<endl;
            else cout<<"NO"<<endl;
        }
        else if(a>=0 && b<=0)
        {
            if(mp['R']>=a && mp['D']>=-b) cout<<"YES"<<endl;
            else cout<<"NO"<<endl;
        }
    }
}