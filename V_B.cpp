#include<bits/stdc++.h>
using namespace std;

#define ll long long
const int M = 1e9+7;
const ll infinity = LLONG_MAX;
int dx[] = {1, 0, -1, 0, 1, 1, -1, -1}; // Right, Down, Left, Up, Right-Up, Right-Down, Left-Up, Left-Down
int dy[] = {0, -1, 0, 1, 1, -1, 1, -1};
inline ll lcm(ll a, ll b) { return (a * b) / __gcd(a, b); }

int v[200100] = {INT_MAX}, seg[4 * 200100] = {INT_MAX}; // Adjusted for 0-based indexing
int n;

void build(int start, int end, int node) 
{ 
    if (start == end) { seg[node] = v[start]; return; }

    int mid = (start + end) / 2; 
    build(start, mid, 2 * node); 
    build(mid + 1, end, 2 * node + 1); 

    seg[node] = min(seg[2 * node], seg[2 * node + 1]);
}
 
int query(int start, int end, int node, int l, int r) 
{    
    // l for left of range in query, r for right of range in query 
    if (r < start || l > end) return INT_MAX; // l..r...start...end or start...end...l...r 
    if (l <= start && r >= end) return seg[node]; // l...start...end...r 

    int mid = (start + end) / 2; 
    int left = query(start, mid, 2 * node, l, r); 
    int right = query(mid + 1, end, 2 * node + 1, l, r); 
    return min(left, right); 
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
   
    cin >> n;

    for (int i = 0; i < n; i++) cin >> v[i]; // Adjusted to 0-based indexing

    build(0, n - 1, 1); // Updated range to 0 to n-1

    ll sum = 0;

    for (int i = 0; i < n; i++) 
    {
        for (int j = i; j < n; j++) 
        {
            // cout << i << " " << j << " " << query(0, n - 1, 1, i, j) << endl;
            sum += query(0, n - 1, 1, i, j);
        }
    }

    cout << sum << endl;
}
