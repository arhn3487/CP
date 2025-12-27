#include<bits/stdc++.h>
using namespace std;

#define ll long long

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin>>t;

    while(t--)
    {
        ll n,x,y,frist,last,seg=0;
        cin>>n;
        vector<pair<ll,ll>> v(n);
        cin>>frist>>last;
        seg=last-frist;

        for(ll i=1;i<n;i++)
        {
            cout<<frist<<" "<<last<<endl;
            cin>>x>>y;
            if(x>=frist && y<=last) continue;
            else if(x>=frist && y>=last) {last=y;continue;}
            else if(x<frist && y<=last){frist=x;continue;}
            else if(x<frist && y>last){frist=x;last=y;continue;};

            //cout<<"qarafat"<<endl;
            ll arr[4];
            arr[0]=x,arr[1]=y,arr[2]=frist,arr[3]=last;
            sort(arr,arr+4);
            frist=arr[0],last=arr[3];
            seg=arr[2]-arr[1];
        }

        cout<<seg<<endl;
    }
}