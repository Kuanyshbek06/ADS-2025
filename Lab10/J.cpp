#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> g(n+1);
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }

    vector<int> visited(n+1, 0);
    int answer = 0;

    for (int start = 1; start <= n; start++) {
        if (visited[start]) continue;

        vector<int> comp;
        queue<int> q;
        q.push(start);
        visited[start] = 1;

        while (!q.empty()) {
            int u = q.front(); q.pop();
            comp.push_back(u);
            for (int v : g[u]) {
                if (!visited[v]) {
                    visited[v] = 1;
                    q.push(v);
                }
            }
        }

        int root = *min_element(comp.begin(), comp.end());

        unordered_set<int> compSet(comp.begin(), comp.end()); 
        queue<int> qq;
        vector<int> parent(n+1, -1);
        vector<int> childCount(n+1, 0);

        qq.push(root);
        parent[root] = 0; 

        while (!qq.empty()) {
            int u = qq.front(); qq.pop();
            for (int v : g[u]) {
                if (parent[v] == -1 && v != root && compSet.count(v)) {
                    parent[v] = u;
                    childCount[u]++;
                    qq.push(v);
                }
            }
        }

        for (int v : comp) {
            if (v == root) {
                answer++; 
            } else {
                if (childCount[v] > childCount[parent[v]])
                    answer++;
            }
        }
    }

    cout << answer;
    return 0;
}
