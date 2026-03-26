#include <bits/stdc++.h>
using namespace std;

vector<int> prefix_function(const string &s) {
    int n = s.size();
    vector<int> pi(n);
    for (int i = 1; i < n; i++) {
        int j = pi[i - 1];
        while (j > 0 && s[i] != s[j])
            j = pi[j - 1];
        if (s[i] == s[j]) pi[i] = j+1;
    }
    return pi;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        long long k;
        cin >> s >> k;
        vector<int> pi = prefix_function(s);
        long long overlap = pi.back();
        long long res = s.size() + (k - 1) * (s.size() - overlap);
        cout << res << "\n";
    }
}
