#include <bits/stdc++.h>
using namespace std;

int main() {
    int q, k;
    cin >> q >> k;
    priority_queue<long long, vector<long long>, greater<long long>> pq;
    long long sum = 0;

    for (int i = 0; i < q; i++) {
        string cmd;
        cin >> cmd;
        if (cmd == "insert") {
            long long x; cin >> x;
            if ((int)pq.size() < k) {
                pq.push(x);
                sum += x;
            } else if (k > 0 && x > pq.top()) {
                sum -= pq.top();
                pq.pop();
                pq.push(x);
                sum += x;
            }
        } else if (cmd == "print") {
            cout << sum << endl;
        }
    }
    return 0;
}
