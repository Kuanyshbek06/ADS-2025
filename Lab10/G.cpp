#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> g;
vector<int> color, parent;
vector<int> cycle;
int n, m;
bool found = false;

void dfs(int v) {
    color[v] = 1;
    for (int u : g[v]) {
        if (color[u] == 0) {
            parent[u] = v;
            dfs(u);
            if (found) return;
        } 
        else if (color[u] == 1) {

            found = true;
            cycle.push_back(u);
            for (int x = v; x != u; x = parent[x])
                cycle.push_back(x);
            reverse(cycle.begin(), cycle.end());
            return;
        }
    }
    color[v] = 2;
}

bool isDAGwithRemovedEdge(int a, int b) {
    vector<int> c(n+1, 0);

    function<bool(int)> dfs2 = [&](int v){
        c[v] = 1;
        for(int u : g[v]) {
            if (v == a && u == b) continue; 
            
            if(c[u] == 1) return false; 
            if(c[u] == 0)
                if(!dfs2(u)) return false;
        }
        c[v] = 2;
        return true;
    };

    for(int i = 1; i <= n; i++)
        if(c[i] == 0)
            if(!dfs2(i)) return false;

    return true;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    g.resize(n+1);
    color.resize(n+1, 0);
    parent.resize(n+1, -1);

    for(int i = 0; i < m; i++){
        int x,y;
        cin >> x >> y;
        g[x].push_back(y);
    }

    for(int i = 1; i <= n; i++) {
        if(color[i] == 0) dfs(i);
        if(found) break;
    }

    if(!found) {
        cout << "YES";
        return 0;
    }

    int k = cycle.size();
    for(int i = 0; i < k; i++) {
        int a = cycle[i];
        int b = cycle[(i+1)%k];

        if(isDAGwithRemovedEdge(a, b)) {
            cout << "YES";
            return 0;
        }
    }

    cout << "NO";
    return 0;
}
