#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll P = 31;
const ll M1 = 1e9 + 7;
const ll M2 = 1e9 + 9;

pair<ll,ll> get_hash(const vector<ll>& h1, const vector<ll>& h2,
                     const vector<ll>& p1, const vector<ll>& p2,
                     int l, int r) {
    ll a = (h1[r] - h1[l] * p1[r - l]) % M1; if (a < 0) a += M1;
    ll b = (h2[r] - h2[l] * p2[r - l]) % M2; if (b < 0) b += M2;
    return {a, b};
}

int main() {
    
    int k;
    cin >> k;
    vector<string> s(k);
    for (int i = 0; i < k; i++) cin >> s[i];

    string base = s[0];
    int n = base.size();

    vector<ll> p1(n + 1, 1), p2(n + 1, 1);
    for (int i = 1; i <= n; i++) {
        p1[i] = (p1[i - 1] * P) % M1;
        p2[i] = (p2[i - 1] * P) % M2;
    }

    vector<ll> h1(n + 1, 0), h2(n + 1, 0);
    for (int i = 0; i < n; i++) {
        int v = base[i] - 'a' + 1;
        h1[i + 1] = (h1[i] * P + v) % M1;
        h2[i + 1] = (h2[i] * P + v) % M2;
    }

    string ans = "";
    for (int len = n; len >= 1 && ans.empty(); len--) {
        for (int i = 0; i + len <= n; i++) {
            auto target = get_hash(h1, h2, p1, p2, i, i + len);
            string sub = base.substr(i, len);
            bool ok = true;

            for (int j = 1; j < k && ok; j++) {
                string &t = s[j];
                int m = t.size();

                vector<ll> ht1(m + 1, 0), ht2(m + 1, 0);
                for (int x = 0; x < m; x++) {
                    int val = t[x] - 'a' + 1;
                    ht1[x + 1] = (ht1[x] * P + val) % M1;
                    ht2[x + 1] = (ht2[x] * P + val) % M2;
                }

                bool found = false;
                for (int z = 0; z + len <= m; z++) {
                    if (get_hash(ht1, ht2, p1, p2, z, z + len) == target) {
                        found = true;
                        break;
                    }
                }
                if (!found) ok = false;
            }

            if (ok) {
                ans = sub;
                break;
            }
        }
    }
    cout << ans << "\n";
}
