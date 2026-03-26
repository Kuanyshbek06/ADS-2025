#include <bits/stdc++.h>
using namespace std;

const long long INF = (long long)1e18;

struct Edge {
    int u, v;
    long long w;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<Edge> edges;
    vector<vector<long long>> a(n+1, vector<long long>(n+1));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> a[i][j];
            if (a[i][j] != 100000) {   
                edges.push_back({i, j, a[i][j]});
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        edges.push_back({0, i, 0});
    }

    vector<long long> dist(n+1, 0);
    vector<int> parent(n+1, -1);

    int x = -1;
    for (int i = 0; i <= n; i++) {
        x = -1;
        for (auto &e : edges) {
            if (dist[e.v] > dist[e.u] + e.w) {
                dist[e.v] = dist[e.u] + e.w;
                parent[e.v] = e.u;
                x = e.v;     
            }
        }
    }

    if (x == -1) {
        cout << "NO\n";
        return 0;
    }

    cout << "YES\n";

    for (int i = 0; i < n; i++) {
        x = parent[x];
    }

    vector<int> cycle;
    int v = x;

    while (true) {
        cycle.push_back(v);
        v = parent[v];
        if (v == x) {
            cycle.push_back(v);
            break;
        }
    }

    reverse(cycle.begin(), cycle.end());

    cout << cycle.size() << "\n";
    for (int v : cycle) cout << v << " ";
    cout << "\n";

    return 0;
}
