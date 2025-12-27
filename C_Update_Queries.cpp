#include<bits/stdc++.h>
using namespace std;

#define ll long long
const ll infinity = LLONG_MAX;
int dx[]={1,0,-1,0,1,1,-1,-1};
int dy[]={0,-1,0,1,1,-1,1,-1};
ll lcm(ll a,ll b) {return (a*b)/__gcd(a,b);}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin>>t;//t=1

    while(t--)
    {
        int n,m;
        
        string s,c;
        cin>>n>>m>>s;
        map<int,char>mp;
        int arr[m];
        for(int i=0;i<m;i++)
        {
            cin>>arr[i];
            mp[arr[i]-1]='z';
        }
        cin>>c;

        sort(c.begin(),c.end());
        //cout<<c<<endl;
        //sort(arr,arr+m);
        int p=mp.size(),i=0;
        auto it = mp.begin();
        while(it!=mp.end())
        {

            it->second=c[i];
            it++;
            i++;
        }
        //for(auto l : mp) cout<<l.first<<l.second<<endl;
        it=mp.begin();
        while(it!=mp.end())
        {
            s[it->first]=it->second;
            //cout<<it->second<<it->first<<endl;
            it++;
            //cout<<s<<endl;
        }
        cout<<s<<endl;
    }
}
