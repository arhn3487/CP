#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;

    while(t--)
    {
        ll x, y, one, two, need;
        cin >> x >> y;

        need = ceil(y * 1.0 / 2); 
        if (y == 0) need = 0;
        
        one = (y == 0) ? 0 : (7 * need);
        if (y % 2 != 0 && y != 0) one += 4;

        if (x == 0 && y == 0) {
            cout << 0 << endl;
        } else if (one >= x) {
            cout << need << endl;
        } else {
            ll a = x - one;
            need += ceil(a * 1.0 / 15); 
            cout << need << endl;
        }
    }

    return 0;
}
