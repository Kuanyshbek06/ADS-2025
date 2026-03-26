#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll P = 31;        
const ll MOD = 1e9 + 9;

vector<ll> build_hash(const string &s, vector<ll> &p_pow) {
    int n = s.size();
    vector<ll> h(n + 1, 0);
    for (int i = 0; i < n; i++)
        h[i + 1] = (h[i] * P + (s[i] - 'a' + 1)) % MOD;
    return h;
}

ll get_hash(const vector<ll> &h, int l, int r, const vector<ll> &p_pow) {
    ll val = (h[r] - h[l] * p_pow[r - l]) % MOD;
    if (val < 0) val += MOD;
    return val;
}

int main() {

    while (true) {
        int n;
        cin >> n;
        if (n == 0) break;

        vector<string> patterns(n);
        for (int i = 0; i < n; i++) cin >> patterns[i];

        string text;
        cin >> text;

        int m = text.size();

        vector<ll> p_pow(m + 1);
        p_pow[0] = 1;
        for (int i = 1; i <= m; i++)
            p_pow[i] = (p_pow[i - 1] * P) % MOD;

        vector<ll> h_text = build_hash(text, p_pow);

        vector<int> cnt(n, 0);

        for (int k = 0; k < n; k++) {
            string &pat = patterns[k];
            int len = pat.size();
            ll h_pat = 0;
            for (char c : pat)
                h_pat = (h_pat * P + (c - 'a' + 1)) % MOD;

            for (int i = 0; i + len <= m; i++) {
                if (get_hash(h_text, i, i + len, p_pow) == h_pat)
                    cnt[k]++;
            }
        }

        int mx = *max_element(cnt.begin(), cnt.end());
        cout << mx << "\n";
        for (int i = 0; i < n; i++)
            if (cnt[i] == mx)
                cout << patterns[i] << "\n";
    }

    return 0;
}
