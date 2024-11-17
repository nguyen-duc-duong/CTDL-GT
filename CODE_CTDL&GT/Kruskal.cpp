#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct Edge {
    int u, v, weight;
    bool operator<(const Edge& other) const {
        return weight < other.weight;
    }
};
int findSet(int u, vector<int>& parent) {
    if (u != parent[u]) {
        parent[u] = findSet(parent[u], parent);
    }
    return parent[u];
}
void unionSet(int u, int v, vector<int>& parent, vector<int>& rank) {
    u = findSet(u, parent);
    v = findSet(v, parent);
    if (u != v) {
        if (rank[u] < rank[v]) {
            swap(u, v);
        }
        parent[v] = u;
        if (rank[u] == rank[v]) {
            rank[u]++;
        }
    }
}
void kruskal(int n, vector<Edge>& edges) {
    sort(edges.begin(), edges.end());
    vector<int> parent(n);
    vector<int> rank(n, 0);

    for (int i = 0; i < n; i++) {
        parent[i] = i;
    }
    vector<Edge> mst;
    int totalWeight = 0;
    for (size_t i = 0; i < edges.size(); i++) {
        int u = edges[i].u;
        int v = edges[i].v;
        if (findSet(u, parent) != findSet(v, parent)) {
            mst.push_back(edges[i]);
            totalWeight += edges[i].weight;
            unionSet(u, v, parent, rank);
        }
    }
    cout << "Cac canh trong cay khung nho nhat (MST):\n";
    for (size_t i = 0; i < mst.size(); i++) {
        cout << mst[i].u << " - " << mst[i].v << " : " << mst[i].weight << "\n";
    }
    cout << "Tong trong so cay khung nho nhat: " << totalWeight << endl;
}
int main() {
    int n, m;
    cout << "Nhap so dinh va so canh: ";
    cin >> n >> m;
    vector<Edge> edges(m);
    cout << "Nhap cac canh (dinh1, dinh2, trong so):\n";
    for (int i = 0; i < m; i++) {
        cin >> edges[i].u >> edges[i].v >> edges[i].weight;
    }
    kruskal(n, edges);
    return 0;
}

