#include<bits/stdc++.h>
using namespace std;

#define ll long long
const ll infinity = LLONG_MAX;
int dx[]={1,0,-1,0,1,1,-1,-1};
int dy[]={0,-1,0,1,1,-1,1,-1};
ll lcm(ll a,ll b) {return (a*b)/__gcd(a,b);}
int x,y;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    t=1;
    cin>>t;

    while(t--)
    {
        int total=0,i=0;
        string a,b;
        cin>>a>>b;
        int ans=0,l1=a.length(),l2=b.length();
        x=a.length(),y=b.length();

        for(int i=0;i<l2;i++)
        {
            int tmp=i;
            int cnt=0;
            for(int j=0;j<l1;j++)
            {
                if(a[j]==b[tmp])
                {
                    cnt++;
                    tmp++;
                }
            }
            ans=max(ans,cnt);
        }

        cout<<a.length()+b.length()-ans<<endl;
    }
}