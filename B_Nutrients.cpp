#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,m,flag=1;
    cin>>n>>m;
    vector<long long>food(m),sum(m);
    long long arr[n][m];

    for(int i=0;i<m;i++) cin>>food[i];
    ////for(int i=0;i<m;i++) cout<<food[i]<<" ";
//cout<<endl;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin>>arr[i][j];
            //cout<<arr[i][j]<<" ";
        }
        //cout<<endl;
    }
    /*for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            //cin>>arr[i][j];
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }*/
    
    for(int i=0;i<m;i++)//col
    {
        long long s=0;
        for(int j=0;j<n;j++)//row
        {
            s+=arr[j][i];
        }
        sum[i] = s;
    }
    /*for (int j = 0; j < m; j++) // col
    {
        long long s = 0;
        for (int i = 0; i < n; i++) // row
        {
            s += arr[i][j];
        }
        sum[j] = s; // Store the column sum in the sum vector
        //cout << s << endl;
    }*/
    

    //for(int i=0;i<n;i++) cout<<sum[i]<<" ";
    for(int i=0;i<m;i++)
    {
        if(food[i]>sum[i])
        {
            flag=0;
            break;
        }
    }

    if(flag) cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
}