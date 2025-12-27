#include <bits/stdc++.h>
using namespace std;

struct Edge {
    int to, weight;
    string msg;
};

struct Path {
    int delay;
    vector<int> nodes;
    string combinedMsg;

    bool operator<(const Path& other) const {
        return delay > other.delay;  // For min-heap
    }
};

int LCS(const string &a, const string &b) {
    int m = a.size(), n = b.size();
    vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
    for (int i = 1; i <= m; ++i)
        for (int j = 1; j <= n; ++j)
            if (a[i-1] == b[j-1])
                dp[i][j] = dp[i-1][j-1] + 1;
            else
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
    return dp[m][n];
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<Edge>> graph(n);
    for (int i = 0; i < m; ++i) {
        int u, v, w;
        string msg;
        cin >> u >> v >> w;
        cin >> ws; // skip whitespace
        char quote;
        cin >> quote; // read opening quote
        getline(cin, msg, '"'); // read until closing quote
        graph[u].push_back({v, w, msg});
        graph[v].push_back({u, w, msg}); // assuming undirected graph
    }

    int start, end;
    string target;
    cin >> start;
    cin >> ws; // skip whitespace
    char quote;
    cin >> quote; // read opening quote
    getline(cin, target, '"'); // read until closing quote
    cin >> end;

    // Dijkstra with path tracking
    vector<int> minDelay(n, INT_MAX);
    priority_queue<Path> pq;
    pq.push({0, {start}, ""});
    minDelay[start] = 0;

    vector<Path> candidates;

    while (!pq.empty()) {
        Path current = pq.top(); pq.pop();
        int u = current.nodes.back();

        if (current.delay > minDelay[u]) continue;

        if (u == end) {
            if (current.delay == minDelay[end]) {
                candidates.push_back(current);
            }
            continue;
        }

        for (auto &e : graph[u]) {
            int v = e.to;
            int newDelay = current.delay + e.weight;
            string newMsg = current.combinedMsg + e.msg;

            if (newDelay <= minDelay[v]) {
                if (newDelay < minDelay[v]) {
                    minDelay[v] = newDelay;
                }
                vector<int> newPath = current.nodes;
                newPath.push_back(v);
                pq.push({newDelay, newPath, newMsg});
            }
        }
    }

    // Select best among candidates
    int maxLCS = -1;
    Path bestPath;
    for (auto &p : candidates) {
        int lcsLen = LCS(p.combinedMsg, target);
        if (lcsLen > maxLCS || (lcsLen == maxLCS && p.delay < bestPath.delay)) {
            maxLCS = lcsLen;
            bestPath = p;
        }
    }

    cout << "Minimum Delay: " << bestPath.delay << "\n";
    cout << "LCS with '" << target << "': " << maxLCS << "\n";
    cout << "Path: ";
    for (size_t i = 0; i < bestPath.nodes.size(); ++i) {
        cout << bestPath.nodes[i];
        if (i != bestPath.nodes.size() - 1)
            cout << " -> ";
    }
    cout << "\n";

    return 0;
}