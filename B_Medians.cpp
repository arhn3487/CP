#include <bits/stdc++.h>
using namespace std;

#define ll long long
const int M = 1e9 + 7;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;

    while (t--) {
        int n, k;
        cin >> n >> k;


        if (n == 1 && k == 1) {
            cout << 1 << "\n1\n";
            continue;
        }

       
        if (n < k || (n % 2 == 0 && k % 2 == 1)) {
            cout << -1 << endl;
            continue;
        }


        int m = (n + 1) / 2; 
        vector<int> positions;
        for (int i = 0; i < m; ++i) {
            positions.push_back(i * 2 + 1);
        }

  
        cout << m << "\n";
        for (int pos : positions) {
            cout << pos << " ";
        }
        cout << endl;
    }
}
