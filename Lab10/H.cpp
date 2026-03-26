#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<string> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    vector<vector<int>> vis(n, vector<int>(m, 0));
    int islands = 0;

    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, 1, -1};

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (a[i][j] == '1' && !vis[i][j]) {
                islands++;

                queue<pair<int,int>> q;
                q.push({i, j});
                vis[i][j] = 1;

                while (!q.empty()) {
                    auto [x, y] = q.front();
                    q.pop();

                    for (int k = 0; k < 4; k++) {
                        int nx = x + dx[k];
                        int ny = y + dy[k];

                        if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
                            if (a[nx][ny] == '1' && !vis[nx][ny]) {
                                vis[nx][ny] = 1;
                                q.push({nx, ny});
                            }
                        }
                    }
                }
            }
        }
    }

    cout << islands;
}
