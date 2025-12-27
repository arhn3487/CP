#include<bits/stdc++.h>
//#include "D:/debug.h"
using namespace std;

#define ll long long
const int M=1e9+7;
const ll infinity = LLONG_MAX;
int dx[]={1,0,-1,0,1,1,-1,-1};//Right,Down,Left,Up,Right-Up,Right-Down,Left-Up,Left-Down
int dy[]={0,-1,0,1,1,-1,1,-1};
ll lcm(ll a,ll b) {return (a*b)/__gcd(a,b);}

class Hash
{
    private:
        int n,mod1=1e9+7,mod2=1e9+9,base1=2147483647,base2= 2147476381;
        string str;
        vector<int> ph1,ph2;
        vector<int> pow1,pow2;

        void prefix_hash()
        {
            int x=0,y=0;
            pow1[0]=1,pow2[0]=1;

            for(int i=0;i<n;i++)
            {
                pow1[i+1]=(1LL*pow1[i]*base1)%mod1;
                pow2[i+1]=(1LL*pow2[i]*base2)%mod2;
                x=(1LL*x*base1+str[i])%mod1;
                y=(1LL*y*base2+str[i])%mod2;
                ph1[i]=x;
                ph2[i]=y;
            }
        }

    public:
        Hash(string s)
        {
            str=s;
            n=str.size();
            ph1.resize(n);
            ph2.resize(n);
            pow1.resize(n+1);
            pow2.resize(n+1);
            prefix_hash();
        }

        pair<int,int> cal_hash(int left,int right)
        {
            if(left==0) return {ph1[right],ph2[right]};
            else
            {
                int x=((ph1[right]-(1LL*ph1[left-1]*pow1[right-left+1])%mod1)+mod1)%mod1;
                int y=((ph2[right]-(1LL*ph2[left-1]*pow2[right-left+1])%mod2)+mod2)%mod2;
                return {x,y};
            }
        }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin>>t;

    while(t--)
    {
        string s;
        int n,m;
        cin>>n>>m>>s;
        Hash h(s);
        set<pair<int,int>> st;

        for(int i=0;i<=n-m;i++)
        {
            pair<int,int> p=h.cal_hash(i,i+m-1);
            st.insert(p);
        }

        cout<<st.size()<<endl;
    }
}