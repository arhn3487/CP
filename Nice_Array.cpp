#include<bits/stdc++.h>
//#include "D:/debug.h"
using namespace std;

#define ll long long
const ll M=1e9+7;
const ll infinity = LLONG_MAX;
ll dx[]={1,0,-1,0,1,1,-1,-1};//Right,Down,Left,Up,Right-Up,Right-Down,Left-Up,Left-Down
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
        ll n,k,sum1=0,sum2=0,b1=0,b2=0;
        ll a;
        cin>>n>>k;

        vector<int> pos,neg,x,y;

        for(ll i=0;i<n;i++) 
        {
            cin>>a;
            if(a>0) pos.push_back(a);
            else if(a<0)neg.push_back(a);
        }

        ll p=pos.size(),ns=neg.size();

        for(ll i=0;i<p;i++)
            
            {
                sum1+=pos[i]/k;
                if(pos[i]%k) b1++;
            }
        
        for(ll i=0;i<ns;i++)
            
            {
                sum2+=-neg[i]/k;
                if(neg[i]%k) b2++;
            }

        ll r1=sum1+b1,r2=sum2+b2;
        //if(k==1) r1-=p,r2-=ns;

        vector<ll> v(4);

        v[0]=sum1;
        v[1]=sum2;
        v[2]=r1;
        v[3]=r2;

        sort(v.begin(),v.end());

        //cout<<sum1<<" "<<r1<<" "<<sum2<<" "<<r2<<endl;

        //if(v[1]<v[2]) cout<<"NO\n";
        if(sum1<=sum2 && r1>=sum2) cout<<"YES\n";
        else if(sum2<=sum1 && r2>=sum1) cout<<"YES\n";
        else cout<<"NO\n";
    }
}