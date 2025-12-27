#include<bits/stdc++.h>
using namespace std;

#define ll long long

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n,k,c=0,i=0;
    cin>>n>>k;
    int arr[n];

    for(int i=0;i<n;i++) cin>>arr[i];
    //cout<<"arafat"<<endl;

    for(i=0;i<n;i++)
    {
        //cout<<i<<endl;
        int sum=0;
        while(i<n)
        {
            if(sum+arr[i]<=k)
            {
                sum+=arr[i];
                i++;
            }
            else {i-- ; break;}
        }
        c++;
    }
    cout<<c<<endl;
}