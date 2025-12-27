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

    for (ll case_num = 1; case_num <= t; case_num++)
    {
        ll n;
        cin >> n;
        vector<ll> v;
        v.push_back(1);

        for (ll factor = 2; factor * factor <= n; factor++)
        {
            if (n % factor == 0)
            {
                ll sz = v.size();

                while (n % factor == 0)
                {
                    n /= factor;
                    ll sz2 = v.size();

                    for (ll j = sz2 - 1; j >= sz2 - sz; j--) 
                        v.push_back(v[j] * factor);
                }
            }
        }

        if (n > 1)
        {
            ll sz2 = v.size();

            for (ll j = sz2 - 1; j >= 0; j--) 
                v.push_back(v[j] * n);
        }

        cout << "Case " << case_num << ":\n";
        for (auto num : v) 
            cout << num << " ";
        cout << "\n";
    }

    return 0;
}
