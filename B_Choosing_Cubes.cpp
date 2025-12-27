#include<bits/stdc++.h>
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
        ll n, f, k;
        cin >> n >> f >> k;
        vector<ll> v(n);

        for (ll i = 0; i < n; i++) 
            cin >> v[i];

        ll tgt = v[f - 1];

        sort(v.begin(), v.end(), greater<ll>());

        ll count_tgt = count(v.begin(), v.begin() + k, tgt);
        ll total_tgt = count(v.begin(), v.end(), tgt);

        if (count_tgt == total_tgt)
            cout << "YES" << endl;
        else if (count_tgt > 0)
            cout << "MAYBE" << endl;
        else
            cout << "NO" << endl;
    }

    return 0;
}
