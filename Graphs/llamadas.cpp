#include <iostream>
#include <limits>
#include <vector>

using namespace std;

int INF = numeric_limits<int>::max();

struct Edge {
    int u, vertices, w;

    Edge(int u, int vertices, int w) : u(u), vertices(vertices), w(w) {}

    // Order edges by weight
    bool operator <(const Edge& x) const {
        return w < x.w;
    }
};

int llamadas(vector<Edge>& Graph, int vertices, int root) {

    // Minimum edge cost for each vertex
    vector<Edge> minInEdge(vertices, Edge(-1, -1, INF));
    for (Edge edges : Graph) {
        minInEdge[edges.vertices] = min(minInEdge[edges.vertices], edges);
    } minInEdge[root] = Edge(-1, root, 0);

    // Assign vertices to the cycle group
    vector<int> group(vertices, 0);
    vector<bool> visited(vertices, false), isCycleGroup(vertices, false);
    int cnt = 0;
    for (int i = 0; i < vertices; i++) {
        if (visited[i])
            continue;

        int node = i; vector<int> path;
        while (node != -1 && !visited[node]) {
            visited[node] = true;
            path.push_back(node);
            node = minInEdge[node].u;
        }

        bool isCycle = false;
        for (int vertices : path) {
            group[vertices] = cnt;
            if (vertices == node)
                isCycleGroup[cnt] = isCycle = true;
            if (!isCycle)
                cnt++;
        }

        if (isCycle)
            cnt++;
    }

    // No more cycles, return
    if (cnt == vertices) {
        int result = 0;
        for (Edge edges : minInEdge)
            result += edges.w;
        return result;
    }

    int result = 0;
    for (Edge edges : minInEdge)
        if (isCycleGroup[group[edges.vertices]])
            result += edges.w;

    // New graph with groups
    vector<Edge> newGraph;
    for (Edge edges : Graph) {
        int u = group[edges.u], vertices = group[edges.vertices], w = edges.w;
        if (u == vertices)
            continue;
        else if (isCycleGroup[vertices])
            newGraph.push_back(Edge(u, vertices, w - minInEdge[edges.vertices].w));
        else
            newGraph.push_back(Edge(u, vertices, w));
    }

    return result + llamadas(newGraph, cnt, group[root]);
}

int main() {

    int vertices, edges;
    int vi, vj, weight;
    vector<Edge> Graph;
    cin >> vertices >> edges;
    for (int i = 0; i < edges; i++) {
        cin >> vi >> vj >> weight;

        Graph.push_back(Edge(vi, vj, weight));
    }

    int result = llamadas(Graph, vertices, 0);

    if (result < numeric_limits<int>::max()) cout << result;
    else cout << "Desconectado!" << endl;
    return 0;
}
