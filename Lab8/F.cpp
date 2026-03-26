#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll P = 31;
const ll MOD1 = 1000000007;
const ll MOD2 = 1000000009;


pair<vector<ll>, vector<ll>> build_hash(const string &s,
                                        const vector<ll> &p1,
                                        const vector<ll> &p2) {
    int n = s.size();
    vector<ll> h1(n + 1, 0), h2(n + 1, 0);
    for (int i = 0; i < n; i++) {
        int val = s[i] - 'a' + 1;
        h1[i + 1] = (h1[i] * P + val) % MOD1;
        h2[i + 1] = (h2[i] * P + val) % MOD2;
    }
    return {h1, h2};
}

ll get_hash(const vector<ll> &h1, const vector<ll> &h2,
            int l, int r,
            const vector<ll> &p1, const vector<ll> &p2) {
    ll a = (h1[r] - h1[l] * p1[r - l]) % MOD1;
    if (a < 0) a += MOD1;
    ll b = (h2[r] - h2[l] * p2[r - l]) % MOD2;
    if (b < 0) b += MOD2;
    return a * 1000000009LL + b;
}

int main() {
    
    string s;
    cin >> s;
    int n = s.size();

    vector<ll> p1(n + 1), p2(n + 1);
    p1[0] = p2[0] = 1;
    for (int i = 1; i <= n; i++) {
        p1[i] = (p1[i - 1] * P) % MOD1;
        p2[i] = (p2[i - 1] * P) % MOD2;
    }

    auto [h1, h2] = build_hash(s, p1, p2);

    long long total = 0;

    for (int len = 1; len <= n; len++) {
        unordered_set<ll> seen;
        seen.reserve(n - len + 1);
        for (int i = 0; i + len <= n; i++) {
            seen.insert(get_hash(h1, h2, i, i + len, p1, p2));
        }
        total += seen.size();
    }

    cout << total << "\n";
    return 0;
}
