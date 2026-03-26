#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        deque<int> dq;

        for (int card = n; card >= 1; card--) {
            dq.push_front(card);

            for (int k = 0; k < card; k++) {
                int last = dq.back();
                dq.pop_back();
                dq.push_front(last);
            }
        }

        for (int i = 0; i < dq.size(); i++) {
            cout << dq[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}
