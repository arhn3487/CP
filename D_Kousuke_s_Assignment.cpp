#include<bits/stdc++.h>
using namespace std;

#define ll long long
const int M=1e9+7;
const ll infinity = LLONG_MAX;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin>>t;

    while(t--)
    {
        int n, cnt=0;
        cin>>n;

        vector<int> v(n);
        map<ll, int> f;
        ll ps = 0;
        f[0] = 1;
        for(int i = 0; i < n; i++) {
            cin >> v[i];
            ps += v[i];
            
            if(f[ps] > 0) {
                cnt++;
                f.clear();
                ps = 0;
                f[0] = 1;
            }
            f[ps]++;
        }

        cout << cnt << endl;
    }
}
