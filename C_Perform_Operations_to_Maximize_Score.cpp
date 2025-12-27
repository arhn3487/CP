#include <bits/stdc++.h>

using namespace std;

#define fastIO                   \
    ios::sync_with_stdio(false); \
    cin.tie(NULL);               \
    cout.tie(NULL);              \
    cout.precision(numeric_limits<double>::max_digits10);
    
#define int long long

void CoderAbhi27()
{
    int n, k;
    cin >> n >> k;
    vector<pair<int, int>> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i].first;
    }
    for (int i = 0; i < n; i++)
        cin >> a[i].second;
    sort(a.begin(), a.end());
    int lo = 0, hi = 2e9, ans = a[n - 1].first;
    while (lo <= hi)
    {
        int mid = lo + (hi - lo) / 2;
        int req = (n - 1) / 2 + 2;
        int rem = k;
        for (int i = n - 1; i >= 0; i--)
        {
            if (a[i].first >= mid)
                req--;
            else if (a[i].second == 1)
            {
                if (mid - a[i].first <= rem)
                {
                    rem -= mid - a[i].first;
                    req--;
                }
            }
        }
        if (req <= 0)
        {
            ans = max(ans, a[n - 1].first + mid);
            lo = mid + 1;
        }
        else
            hi = mid - 1;
    }

    int j = -1;
    for (int i = n - 1; i >= 0; i--)
    {
        if (a[i].second == 1)
        {
            j = i;
            break;
        }
    }
    if (j == -1)
    {
        cout << ans << '\n';
        return;
    }
    if (j <= n / 2 - 1)
    {
        ans = max(ans, a[n / 2].first + a[j].first + k);
    }
    else
    {
        ans = max(ans, a[n / 2 - 1].first + a[j].first + k);
    }
    cout << ans << '\n';
}

int32_t main()
{
    fastIO;

    int t = 1;
    cin >> t;
    while (t--)
    {
        CoderAbhi27();
    }
    return 0;
}