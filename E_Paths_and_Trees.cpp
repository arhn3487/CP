#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<ll, int>

const int MAX_NODES = 300010;
const int MAX_EDGES = 600010;

int numNodes, numEdges, startNode;

// Adjacency list representation
int head[MAX_NODES], edgeTo[MAX_EDGES], nextEdge[MAX_EDGES], edgeWeight[MAX_EDGES], edgeIndex = 0;

ll minDistance[MAX_NODES];
bool visited[MAX_NODES];
int lastUsedEdgeIndex[MAX_NODES];

priority_queue<pii, vector<pii>, greater<pii>> minHeap;

void addEdge(int from, int to, int weight) {
    edgeIndex++;
    edgeTo[edgeIndex] = to;
    edgeWeight[edgeIndex] = weight;
    nextEdge[edgeIndex] = head[from];
    head[from] = edgeIndex;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> numNodes >> numEdges;

    // Input edges (undirected)
    for (int i = 1; i <= numEdges; i++) {
        int from, to, weight;
        cin >> from >> to >> weight;
        addEdge(from, to, weight);
        addEdge(to, from, weight); // since it's undirected
    }

    cin >> startNode;

    // Initialize distances
    memset(minDistance, 0x3f, sizeof minDistance);
    minDistance[startNode] = 0;
    minHeap.push({0, startNode});

    // Dijkstra's algorithm
    while (!minHeap.empty()) {
        int currentNode = minHeap.top().second;
        minHeap.pop();

        if (visited[currentNode]) continue;
        visited[currentNode] = true;

        for (int i = head[currentNode]; i; i = nextEdge[i]) {
            int neighbor = edgeTo[i];
            int weight = edgeWeight[i];

            if (minDistance[neighbor] > minDistance[currentNode] + weight) {
                minDistance[neighbor] = minDistance[currentNode] + weight;
                lastUsedEdgeIndex[neighbor] = i;
                minHeap.push({minDistance[neighbor], neighbor});
            } else if (minDistance[neighbor] == minDistance[currentNode] + weight) {
                // Choose the smaller weight edge if multiple paths have same distance
                if (weight < edgeWeight[lastUsedEdgeIndex[neighbor]]) {
                    lastUsedEdgeIndex[neighbor] = i;
                }
            }
        }
    }

    // Calculate total weight of the shortest-path tree
    ll totalWeight = 0;
    for (int i = 1; i <= numNodes; i++) {
        if (i == startNode) continue;
        totalWeight += edgeWeight[lastUsedEdgeIndex[i]];
    }
    cout << totalWeight << "\n";

    // Output used edge indices (original 1-based edge number)
    vector<int> usedEdges;
    for (int i = 1; i <= numNodes; i++) {
        if (i == startNode) continue;
        usedEdges.push_back((lastUsedEdgeIndex[i] + 1) / 2);
    }

    sort(usedEdges.begin(), usedEdges.end());
    for (int edgeNum : usedEdges) {
        cout << edgeNum << " ";
    }

    return 0;
}
