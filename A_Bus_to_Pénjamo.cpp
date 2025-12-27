#include<bits/stdc++.h>
//#include "D:/debug.h"
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin>>t;

    while(t--)
    {
        int n,m,h=0,a,ext=0,b=0;
        cin>>n>>m;
        vector<int> v;

        for(int i=0;i<n;i++)
        {
            cin>>a;
            h+=2*(a/2);
            ext+=a%2;
            if(a!=1) b+=(a/2);
        }

        if(ext%2) 
        {
            h++;
            b++;
            ext--;
        }
        int khali_row=m-b;
        //cout<<h<<" "<<khali_row<<" "<<ext<<endl;
        if(khali_row>=ext) h+=ext;
        else
        {
            int sob_golate_ak_ta_kore_dile_thake=ext-khali_row;
            h+=ext-2*sob_golate_ak_ta_kore_dile_thake;
        }
        //cout<<h<<" "<<khali_row<<endl;
        //int akn_o_khali=khali_row-(ext/2);

        cout<<h<<endl;
    }
}