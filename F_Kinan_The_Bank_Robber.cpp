#include <bits/stdc++.h>
//#include "D:/debug.h"
using namespace std;

int main()
{
    int n, f = 1;
    cin >> n;
    map<int, int> cnta, cntb;
    vector<int> v(n), ans(n,1);

    for (auto &x : v)
        cin >> x;

    for (int i = 0; i < n; i++)
    {
        bool flag = true;
        
        vector<int> p;
        int x = v[i];
        for(int j=2;j*j<=x;j++){
            if(x%j==0){
                p.push_back(j);
                while(x%j==0) x/=j;
            }
        }
        if(x>1) p.push_back(x);
        if(x==1 && v[i]==1) p.push_back(1);

        //debug(p);

        for (auto x : p)
        {
            if (cnta[x])
                flag = false;
            cnta[x]++;
        }

        if (flag == false)
        {
            for (auto x : p)
            {
                if ((cnta[x] + cntb[x] > 2) or cntb[x])
                {
                    cout << -1 << '\n';
                    return 0;
                }
                cnta[x]--;
                cntb[x]++;
            }
            ans[i]=2;
        }

        // for(auto x : p)
        // {
        //     if (cnta[x] + cntb[x] > 2)
        //     {
        //         cout << -1 << '\n';
        //         return 0;
        //     }
        // }
        // for (auto x : p)
        //     cout << x << ' ';
        // cout << '\n';

        
    }

    //cout << "AR\n";

    // for(auto [x,y] : cnta)
    // {
    //     if(y>=2)
    //     {
    //         cout<<-1<<'\n';
    //         return 0;
    //     }
    // }
    // for(auto [x,y] : cntb)
    // {
    //     if(y>=2)
    //     {
    //         cout<<-1<<'\n';
    //         return 0;
    //     }
    // }
   
    for (int i = 0; i < n; i++)
        cout << ans[i] << ' ';
}