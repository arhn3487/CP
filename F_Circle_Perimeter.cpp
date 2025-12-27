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
        ll r,cnt=0;
        cin>>r;
        
        for(int i=0;i<=r;i++)
        {
            ll x = r-i;
            ll y1 = sqrt(pow(r,2)-pow(x,2));
            ll y2 = sqrt(pow(r+1,2)-pow(x,2));

            if(pow(x,2)+pow(y1,2)<pow(r,2)) y1++;
            if(pow(x,2)+pow(y2,2)>=pow(r+1,2)) y2--;
            cnt+=y2-y1+1;
        }
        
        cnt-=2;
        cnt*=4;
        cnt+=4;

        cout<<cnt<<endl;
    }
}