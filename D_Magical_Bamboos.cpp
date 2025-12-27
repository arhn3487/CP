#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;

    while(t--)
    {
        int n,a;
        cin>>n;
        set<int> st;
        map<int,int> mp;

        for(int i=0;i<n;i++)
        {
            cin>>a;
            st.insert(a);
            mp[a]++;
        }

        if(st.size()==1) cout<<"yes"<<endl;
        else if(st.size()>2) cout<<"no"<<endl;
        else
        {
            pair<long long,long long> p,q;
            p=*mp.begin();
            q=*mp.rbegin();
            int a = p.first,b=p.second,c=q.first,d=q.second;
            if((b==1 || d==1) && b!=d)
            {
                if(abs(a-c)%2==0) cout<<"yes"<<endl;
                
            }
            else cout<<"no"<<endl;
        }
    }
}