#include <bits/stdc++.h>
using namespace std;

int main() {
    long long n, m;
    cin >> n >> m;

    if (n == m) {
        cout << 0;
        return 0;
    }

    vector<long long> path;
    long long cur = m;

    while (cur > n) {
        path.push_back(cur);
        if (cur % 2 == 1) {
            cur++;      
        } else {
            cur /= 2;   
        }
    }

    while (cur < n) {
        path.push_back(cur);
        cur++;
    }

    reverse(path.begin(), path.end());

    cout << path.size() << "\n";
    for (long long x : path) cout << x << " ";
}
