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
        int j=0,l,one=0,zero=0;
        string a,b;
        cin>>l>>a>>b;
        vector<pair<ll,ll>> v;
        

        for(int i=0;i<l;i++)
        {
            if(a[i]=='1') one++;
            else zero++;

            if(one==zero)
            {
                v.push_back({j,i});
                j=i+1;
                one=0;
                zero=0;
            }
        }
        for(auto p : v)
        {
            int start=p.first;
            int end=p.second;

            if(a[start]==b[start]) continue;
            
            for(int i=start;i<=end;i++)
            {
                if(a[i]=='1') a[i]='0';
                else a[i]='1';
            }
        }

        bool flag=true;
        for(int i=0;i<l;i++)
        {
            if(a[i]!=b[i])
            {
                cout<<"NO"<<endl;
                flag=false;
                break;
            }
        }

        if(flag) cout<<"YES"<<endl;
    }
}