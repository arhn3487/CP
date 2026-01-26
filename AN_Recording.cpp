#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, c;
    cin >> n >> c;

    int start[100010];
    int fin[100010];
    memset(start, 0, sizeof(start));
    memset(fin, 0, sizeof(fin));

    vector<pair<int, int>> channels[31];
    vector<pair<int, int>> marge[31];

    for (int i = 0; i < n; ++i) {
        int s, t, ci;
        cin >> s >> t >> ci;
        channels[ci].push_back({s, t});
    }

    for (int i = 1; i <= 30; ++i) {
        if (channels[i].size() == 0) continue;
        
        sort(channels[i].begin(), channels[i].end());

        int st = channels[i][0].first;
        int en = channels[i][0].second;

        for (int j = 1; j < channels[i].size(); ++j) {
            if (channels[i][j].first == en) {
                en = channels[i][j].second;
            } else {
                marge[i].push_back({st, en});
                st = channels[i][j].first;
                en = channels[i][j].second;
            }
        }
        marge[i].push_back({st, en});
    }

    for (int i = 1; i <= 30; ++i) {
        for (auto p : marge[i]) {
            start[p.first]++;
            fin[p.second]++;
        }
    }

    int active = 0;
    int free = 0;

    for (int i = 0; i < 100005; ++i) {
        if (free <= start[i]) {
            active += (start[i]);
            free = 0;
        } else if (free > start[i]) {
            active += start[i];
            free -= start[i];
        }
        free += fin[i];
        active -= fin[i];
    }

    cout << active + free << endl;

    return 0;
}