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

    while(t--)
    {
        int n;
        cin >> n;
        vector<int> v(n);

        for(int i = 0; i < n; i++) cin >> v[i];

        int m;
        cin >> m;

        while(m--)
        {
            string s;
            cin >> s;

            if (s.length() != n) {
                cout << "NO\n";
                continue;
            }

            unordered_map<char, int> mp;
            unordered_map<int, char> mp1;
            bool flag = true;

            for(int i = 0; i < s.length(); i++)
            {
                if(mp.find(s[i]) == mp.end() && mp1.find(v[i]) == mp1.end()) {
                    mp[s[i]] = v[i];
                    mp1[v[i]] = s[i];
                } 
                else if(mp[s[i]] != v[i] || mp1[v[i]] != s[i]) {
                    flag = false;
                    break;
                }
            }

            if(flag) cout << "YES\n";
            else cout << "NO\n";
        }
    }
}
