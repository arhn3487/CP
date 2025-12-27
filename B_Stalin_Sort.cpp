#include<bits/stdc++.h>
//#include "D:/debug.h"
using namespace std;

#define ll long long
const int M=1e9+7;
const ll infinity = LLONG_MAX;
int dx[]={1,0,-1,0,1,1,-1,-1};//Right,Down,Left,Up,Right-Up,Right-Down,Left-Up,Left-Down
int dy[]={0,-1,0,1,1,-1,1,-1};
inline ll lcm(ll a,ll b) {return (a*b)/__gcd(a,b);}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin>>t;

    while(t--)
    {
        int n,cnt=0,mx,cnt1=0;
        cin>>n;
        vector<int> v(n);
        //set<int> st;

        for(int i=0;i<n;i++) 
        {
            cin>>v[i];
            //st.insert(v[i]);
        }

        int j=0;
        while(j<n-1 && v[j]==v[j+1]) j++;

        mx=v[j];
        

        for(int i=j+1;i<n;i++)
        {
            //cout<<i<<" "<<v[i]<<" "<<mx<<endl;
            if(v[i]>=mx)
            {
                //cout<<i<<"\n";
                mx=v[i];
                cnt++;
            }
        }

        bool inc=false;
        for(int i=0;i<n-1;i++)
        {
            if(v[i]>v[i+1]) break;
            else if(i==n-2 && v[i]<=v[i+1])
            {
                int k=n-1,a=0;
                while(k>0 && v[k]==v[k-1]) 
                {
                    a++;
                    k--;
                }
                
                cnt=min(n-a-1,cnt);
                //cout<<a+1<<" "<<n-a-1<<endl;
            }
        }

         set<int> st;
         st.insert(v[0]);

        for(int l=0;l<n-1;l++)
        {
            if(v[l]<=v[l+1]) st.insert(v[l+1]);
        }

       
        if(st.size()==1) cnt=0;
        //int cnt=1;

        cout<<cnt<<endl;
        //cout<<min(cnt1,cnt)<<endl;
    }
}

 int ans = n;
    for (int i = 0; i < n; i++) {
        int res = 0;
        for (int j = 0; j < n; j++) {
            if (j < i || a[j] > a[i]) {
                res++;
            }
        }
        ans = std::min(ans, res);
    }