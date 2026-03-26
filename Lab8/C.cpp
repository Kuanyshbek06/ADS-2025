#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll P = 31;
const ll MOD = 1e9 + 9;

int main() {

    string s;
    int n;
    cin >> s >> n;

    vector<string> t(n);
    for (int i = 0; i < n; i++) cin >> t[i];

    int m = s.size();

    vector<ll> p_pow(m + 1);
    p_pow[0] = 1;
    for (int i = 1; i <= m; i++)
        p_pow[i] = (p_pow[i - 1] * P) % MOD;

    vector<ll> hs(m + 1, 0);
    for (int i = 0; i < m; i++)
        hs[i + 1] = (hs[i] * P + (s[i] - 'a' + 1)) % MOD;

    auto get_hash = [&](int l, int r) {
        ll val = (hs[r] - hs[l] * p_pow[r - l]) % MOD;
        if (val < 0) val += MOD;
        return val;
    };

    vector<bool> covered(m, false);

    for (string &x : t) {
        int len = x.size();
        ll h = 0;
        for (char c : x)
            h = (h * P + (c - 'a' + 1)) % MOD;

        
        for (int i = 0; i + len <= m; i++) {
            if (get_hash(i, i + len) == h){
                for (int j = i; j < i + len; j++)
                    covered[j] = true;
            }
        }
    }

    bool ok = all_of(covered.begin(), covered.end(), [](bool v) { return v; });

    cout << (ok ? "YES\n" : "NO\n");
    return 0;
}

