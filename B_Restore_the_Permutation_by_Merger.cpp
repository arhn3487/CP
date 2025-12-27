#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;

    while(t--)
    {
        int n;
        cin>>n;
        int arr[2*n];
        set<int> st;

        for(int i=0;i<2*n;i++)
        {
            cin>>arr[i];
            if(st.find(arr[i])==st.end()) 
            {
                cout<<arr[i]<<" ";
                st.insert(arr[i]);
            }
        }
        cout<<endl;
    }
}