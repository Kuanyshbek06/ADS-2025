#include <bits/stdc++.h>
using namespace std;

int main() {
    int m, n;
    cin >> m >> n;

    vector<vector<int>> a(m, vector<int>(n));
    queue<pair<int,int>> q;

    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
            if (a[i][j] == 2) q.push({i, j}); 
        }

    bool has_mushroom = false;
    for (auto &row : a)
        for (int x : row)
            if (x == 1) has_mushroom = true;
    if (!has_mushroom) {
        cout << 0;
        return 0;
    }

    int dirs[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
    int minutes = 0;

    // BFS
    while (!q.empty()) {
        int sz = q.size();
        bool changed = false;

        while (sz--) {
            auto [x, y] = q.front();
            q.pop();

            for (auto &d : dirs) {
                int nx = x + d[0], ny = y + d[1];
                if (nx < 0 || nx >= m || ny < 0 || ny >= n) continue;

                if (a[nx][ny] == 1) {  
                    a[nx][ny] = 2;
                    q.push({nx, ny});
                    changed = true;
                }
            }
        }

        if (changed) minutes++;
    }

    for (auto &row : a)
        for (int x : row)
            if (x == 1) {
                cout << -1;
                return 0;
            }

    cout << minutes;
}