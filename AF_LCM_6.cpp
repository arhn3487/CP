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
        ll n;
        cin>>n;
        vector<ll> v(n);
        
        for(ll i =0;i<n;i++) cin>>v[i];
        sort(v.begin(),v.end());
        
        bool flag=true;
        for(ll i=0;i<n;i++)
        {
            if(v[n-1]%v[i]!=0) flag=false;
        }
        

        if(flag==false) 
        {
            cout<<n<<endl;
        }
        else
        {
            //cout<<"ar"<<t<<endl;
            set<ll> st;
            ll b=v[n-1];
            for(ll i=1;i*i<=b;i++)
            {
                if(b%i==0)
                {
                    st.insert(i);
                    st.insert(b/i);
                }
            }
            //cout<<"ar"<<t<<endl;
            ll ans=0; 

            for(auto it : st)
            {
                ll tmp=0,x=it;
                vector<ll> vec;
                bool valid=true;

                for(ll i=0;i<n;i++)
                {
                    if(x==v[i]) valid=false;
                    if(x%v[i]==0)
                    {
                        vec.push_back(v[i]);
                    }
                }
                ll lcm=1;
                for(auto  it2 : vec)
                {
                    lcm=lcm*it2/__gcd(lcm,it2);
                }
                ll sz=vec.size();
                if(lcm==x && valid)ans=max(ans,sz);
            }
            cout<<ans<<endl;
        }
    }
}