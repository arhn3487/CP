#include<bits/stdc++.h>
using namespace std;

#define ll long long

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll n,a;
    set<ll> st;
    cin>>n;

    for(ll i=0;i<n;i++)
    {
        cin>>a;
        st.insert(a);
    }
    if(st.size()==1)
    {
        cout<<"NO"<<endl;
        return 0;
    }
    auto it = st.begin();
    it++;

    cout<<*it<<endl;
}