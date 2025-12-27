#include<bits/stdc++.h>
#include"D:\debug.h"
using namespace std;

int main()
{
    
    int t;
    cin>>t;

    while(t--)
    {
        long long n,l,r,cnt=0,a,start=0;
        cin>>n>>l>>r;
        vector<long long> v(n);

        for(int i=0;i<n;i++)
        {
            cin>>v[i];
        }
        long long s=v.size(),sum=0;
        
        for(int i=0;i<n;i++)
        {
            if(v[i]>r)
            {
                start=i+1;
                sum=0;
                continue;
            }
            sum+=v[i];
            if(sum>r)
        {
            while(sum>r)
            {
                sum-=v[start];
                start++;
            }
        }
            if(sum>=l && sum<=r)
            {
                start=i+1;
                sum=0;
                cnt++;
                continue;
            }
            
        
        }

        cout<<cnt<<endl;
    }
}
