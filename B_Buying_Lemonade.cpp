#include<bits/stdc++.h>
//#include "D:/debug.h"
using namespace std;

#define int long long
const int M=1e9+7;
//const ll infinity = LLONG_MAX;
int dx[]={1,0,-1,0,1,1,-1,-1};//Right,Down,Left,Up,Right-Up,Right-Down,Left-Up,Left-Down
int dy[]={0,-1,0,1,1,-1,1,-1};
//inline ll lcm(ll a,ll b) {return (a*b)/__gcd(a,b);}

int_fast32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin>>t;

    while(t--)
    {
        int n,total=0,press=0,k,pre_sum=0;
        cin>>n>>k;
        int sz=n,ind=0;

        int arr[n];

        for(int i=0;i<n;i++) cin>>arr[i];

        sort(arr,arr+n);

        while(ind<n)
        {
            //cout<<"ARAft\n";
            if(ind==0) pre_sum=0;
            else pre_sum=arr[ind-1];
            int poss_this=arr[ind]-pre_sum;
            int total_poss=poss_this*sz;
            if(total_poss+total>=k)
            {
                //cout<<total<<" "<<total_poss<<endl;
                cout<<press+(k-total)<<endl;
                break;
            }
            if(total_poss==0) 
            {
                press++;
                ind++;
                sz--;
                //pre_sum=arr[ind];
                //cout<<ind<<" "<<press<<" "<<total<<" "<<poss_this<<" "<<total_poss<<" "<<pre_sum<<endl;
                continue;
            }
            total+=total_poss;
            press+=total_poss+1;
            sz--;
            ind++;
            //pre_sum=arr[ind];

            //cout<<total_poss<<" "<<total<<" "<<ind<<" "<<press<<endl;
        }
    }
}