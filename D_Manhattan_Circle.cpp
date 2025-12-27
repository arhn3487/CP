#include <bits/stdc++.h>
using namespace std;

#define ll long long
const ll infinity = LLONG_MAX;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;

    while (t--)
    {
        ll n, m, prev=0, h = 0, k = 0, a = 0,red=0;
        char ch;
        cin >> n >> m;
        //char arr[n + 1][m + 1];

        for (int i = 1; i <= n; i++)
        {
            int cnt = 0, r = 0;
            for (int j = 1; j <= m; j++)
            {
                cin >> ch;
                if (ch == '#')
                {
                    cnt++;
                    r = j;
                }
                if (cnt == 1) a = j;
                else a = 0;
            }

            if (cnt > prev)
            {
                prev=cnt;
                h = r - cnt / 2;
                red=cnt/2;
            }
            if(a)
            {
                k=i-red;
            }
        }
        cout<<k<<" "<<h<<endl;
    }
}