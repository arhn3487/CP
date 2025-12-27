#include<bits/stdc++.h>
using namespace std;

int main()
{
    long long t;
    cin>>t;

    while(t--)
    {
        long long n;
        cin>>n;
        vector<pair<long long,long long>> v(n); 

        long long x1,x2,y1,y2;

        for(long long i=0;i<n;i++)
        {
            cin>>v[i].first>>v[i].second;
        }

        cin>>x1>>y1>>x2>>y2;

        long long r=(x1-x2)*(x1-x2)+(y1-y2)*(y1-y2);

        bool flag=true;

        for(long long i=0;i<n;i++)
        {
            long long dist=(v[i].first-x2)*(v[i].first-x2)+(v[i].second-y2)*(v[i].second-y2);

            if(dist<=r)
            {
                flag=false;
                break;
            }
        }
        //v.clear();
        if(flag) cout<<"YES\n";
        else cout<<"NO\n";
    }
}
