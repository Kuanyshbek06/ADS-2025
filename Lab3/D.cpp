#include <bits/stdc++.h>
using namespace std;

int main() {

    int n, q;
    cin >> n >> q;
    vector<long long> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    sort(a.begin(), a.end());

    while (q--) {
        long long l1, r1, l2, r2;
        cin >> l1 >> r1 >> l2 >> r2;

        auto cnt1 = upper_bound(a.begin(), a.end(), r1) -
                    lower_bound(a.begin(), a.end(), l1);
        auto cnt2 = upper_bound(a.begin(), a.end(), r2) -
                    lower_bound(a.begin(), a.end(), l2);

        long long both = 0;
        long long L = max(l1, l2), R = min(r1, r2);
        if (L <= R)
            both = upper_bound(a.begin(), a.end(), R) -
                   lower_bound(a.begin(), a.end(), L);

        cout << (cnt1 + cnt2 - both) << "\n";
    }
    return 0;
}
