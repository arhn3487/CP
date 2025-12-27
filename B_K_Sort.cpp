#include<bits/stdc++.h>
using namespace std;

#define ll long long
const ll infinity = LLONG_MAX;
int dx[]={1,0,-1,0,1,1,-1,-1};
int dy[]={0,-1,0,1,1,-1,1,-1};
ll lcm(ll a,ll b) {return (a*b)/__gcd(a,b);}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    t=1;
    cin>>t;

    while(t--)
    {
        int n;
        ll sum=0,z=0;
        cin>>n;
        int arr[n],b[n],f[n];
        for(int i=0;i<n;i++) 
        {
            cin>>arr[i];
            f[i]=arr[i];
        }
        vector<int> v;

        for(int i=1;i<n;i++)
        {
            int a=max(arr[i-1],arr[i]);
            b[i]=a;
            arr[i]=a;
        }
        b[0]=arr[0];
        /*for(int i=0;i<n;i++) cout<<b[i]<<" ";
        cout<<endl;
        for(int i=0;i<n;i++) cout<<f[i]<<" ";
        cout<<endl;*/
        /*if(n==1)
        {
            int c=arr[0];
            sum=c*(c+1);
            cout<<sum<<endl;
            continue;
        }*/

        for(int i=0;i<n;i++)
        {
            if(b[i]-f[i]) v.push_back(b[i]-f[i]);
        }
        sort(v.begin(),v.end());
        int k=v.size()+1;
       // auto last = unique(v.begin(), v.end());

    
        //v.erase(last, v.end());
       
        for(int i=0;i<v.size();i++)
        {
            sum+=(v[i]-z)*k;
            
            k--;
            z=v[i];
            
        }

        cout<<sum<<endl;

    }
}