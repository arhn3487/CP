#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;

    while(t--)
    {
        int n,a,left=0,cnt=0;
        cin>>n;

        //int n;
        map<int,int> mp;
        for(int i=0;i<n;i++)
        {
            cin>>a;
            mp[a]++;
        }

        for(auto num : mp)
        {
            int total = (num.second+left)/num.first;
            left = (num.second+left)%num.first;
            cnt+=total;
        }

        cout<<cnt<<endl;
    }
}