#include<bits/stdc++.h>
using namespace std;

#define ll long long

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n,l,r;
    cin>>n;
    set<int> st;

    for(int i=0;i<n;i++)
    {
        cin>>l>>r;
        for(l;l<=r;l++)
        {
            st.insert(l);
        }
    }

    int i=0;
    
    for(auto num : st)
    {
        if(i==n) break;
        cout<<num<<" ";
        i++;
    }
}