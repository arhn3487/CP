#include <bits/stdc++.h>
using namespace std;

#ifndef ONLINE_JUDGE
#include "C:/Users/ASUS/Documents/debug.h"
#else
#define debug(...)
#define debugArr(...)
#endif

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
        ll m = 0, s = 0, n, cnt = 0;
        cin >> n;
        ll sum[n], mx[n], arr[n];

        for (ll i = 0; i < n; i++)
        {
            cin >> arr[i];
            s += arr[i];
            m = max(arr[i], m);
            mx[i] = m;
            sum[i] = s;
        }

        for (int i = 0; i < n; i++)
        {
            if (sum[i] - mx[i] == mx[i])
                cnt++;
        }

        cout << cnt << endl;
        debug(sum);
    }
}