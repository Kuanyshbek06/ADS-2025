#include <bits/stdc++.h>
using namespace std;

const long long MOD = 1e9 + 7;
const long long P = 11;

long long getHash(const string &s) {
    long long h = 0, p_pow = 1;
    for (char c : s) {
        h = (h + (c - 47) * p_pow) % MOD;
        p_pow = (p_pow * P) % MOD;
    }
    return h;
}

int main() {
  
    int n;
    cin >> n;
    vector<string> arr(2 * n);
    for (int i = 0; i < 2 * n; i++) cin >> arr[i];

   
    unordered_set<string> hashes;
    for (auto &x : arr) hashes.insert(x);

    int printed = 0;
    for (auto &s : arr) {
        if (!all_of(s.begin(), s.end(), ::isdigit)) continue;
        string h = to_string(getHash(s));
        if (hashes.count(h)) {
            cout << "Hash of string \"" << s << "\" is " << h << "\n";
            printed++;
            if (printed == n) break; 
        }
    }
}


