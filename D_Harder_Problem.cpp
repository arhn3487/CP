#include<bits/stdc++.h>
using namespace std;

#define ll long long
const int M = 1e9 + 7;
const ll infinity = LLONG_MAX;
int dx[] = {1, 0, -1, 0, 1, 1, -1, -1};  // Right, Down, Left, Up, Right-Up, Right-Down, Left-Up, Left-Down
int dy[] = {0, -1, 0, 1, 1, -1, 1, -1};
inline ll lcm(ll a, ll b) { return (a * b) / __gcd(a, b); }

#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define YES cout << "YES\n";
#define NO cout << "NO\n";

void solve()
{
    map<int, int> mp;
    set<pair<int, int>> st;
    int n, a;
    vector<int> v, x;
    unordered_set<int> u;
    stack<int> stk;

    cin >> n;
    v.resize(n);

    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
        if(stk.empty()) stk.push(v[i]);
        else if(stk.top()!=v[i]) stk.push(v[i]);
    }

    while(!stk.empty())
    {
        x.push_back(stk.top());
        stk.pop();
    }

    reverse(all(x));

    cout << v[0] << ' ';
    mp[v[0]]++;
    int start = 1,mx=v[0];
    st.insert({1, v[0]});

    for (int i = 1; i < n; i++)
    {
        auto q = *st.rbegin();
        if (mx == v[i])
        {
            if (start < x.size())
            {
                cout << x[start] << ' ';
                start++;
                mp[x[start]]++;
                st.insert({mp[x[start]], x[start]});
                mx=x[start];
            }
            else
            {
                cout << v[i] << ' ';
                mp[v[i]]++;
                st.insert({mp[v[i]], v[i]});
                mx=v[i];
            }
        }
        else
        {
            cout << v[i] << ' ';
            mp[v[i]]++;
            st.insert({mp[v[i]], v[i]});
            mx=v[i];
        }
    }
    cout << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t = 1;
    cin >> t;

    for (int i = 1; i <= t; i++)
    {
        solve();
    }
}
