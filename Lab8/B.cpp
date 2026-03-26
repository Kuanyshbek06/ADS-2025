#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll P = 31;
const ll MOD = 1e9 + 9;

int main() {

    string s1, s2, t;
    cin >> s1 >> s2 >> t;

    int n = s1.size();
    int m = t.size();

    
    vector<ll> p_pow(n + 1);
    p_pow[0] = 1;
    for (int i = 1; i <= n; i++)
        p_pow[i] = (p_pow[i - 1] * P) % MOD;

    
    auto make_hash = [&](const string& s) {
        int len = s.size();
        vector<ll> h(len + 1, 0);
        for (int i = 0; i < len; i++)
            h[i + 1] = (h[i] * P + (s[i] - 'a' + 1)) % MOD;
        return h;
    };

    vector<ll> h1 = make_hash(s1);
    vector<ll> h2 = make_hash(s2);
    vector<ll> ht = make_hash(t);
    ll hash_t = ht[m]; 

    auto get_hash = [&](const vector<ll>& h, int l, int r) {
        
        ll val = (h[r] - h[l] * p_pow[r - l]) % MOD;
        if (val < 0) val += MOD;
        return val;
    };

    int cnt = 0;
    for (int i = 0; i + m <= n; i++) {
        ll hash1 = get_hash(h1, i, i + m);
        ll hash2 = get_hash(h2, i, i + m);
        if (hash1 == hash_t && hash2 == hash_t)
            cnt++;
    }

    cout << cnt << "\n";
    return 0;
}