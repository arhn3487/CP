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
        ll n,a,cnt=0;
        cin>>n;
        set<ll> st;

        for(ll i=0;i<n;i++)
        {
            cin>>a;
            if(a%2==0)st.insert(a);
        }
        //cout<<st.size()<<endl;
        while(!st.empty())
        {
            auto it = st.end();
            it--;
            a=*it;
            
            if(a%2)
            {
                st.erase(it);
            }
            else
            {
                cnt++;
                st.erase(it);
                st.insert(a/2);
            }
            //cout<<a<<"f"<<cnt<<endl;
        }
        cout<<cnt<<endl;
    }
}