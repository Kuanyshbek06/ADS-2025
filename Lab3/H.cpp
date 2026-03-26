#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<long long> ends(n);
    long long sum = 0;
    for (int i = 0; i < n; i++) {
        long long x; cin >> x;
        sum += x;
        ends[i] = sum; 
    }

    while (m--) {
        long long line;
        cin >> line;
        int block = lower_bound(ends.begin(), ends.end(), line) - ends.begin();
        cout << block + 1 << "\n";
    }
    return 0;
}
