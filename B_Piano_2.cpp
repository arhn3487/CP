#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> a(n), b(m);

    for(int i = 0; i < n; i++) 
    {
        cin >> a[i];
    }
    for(int i = 0; i < m; i++) 
    {
        cin >> b[i];
    }

    vector<int> c(n + m);
    merge(a.begin(), a.end(), b.begin(), b.end(), c.begin());
    sort(c.begin(), c.end());

    bool flag = false;

    for(int i = 1; i < n + m; i++) 
    {
        if(find(a.begin(), a.end(), c[i]) != a.end() && find(a.begin(), a.end(), c[i - 1]) != a.end()) 
        {
            flag = true;
            break;
        }
    }
    
    if(flag) cout << "Yes" << endl;
    else cout << "No" << endl;

    return 0;
}
