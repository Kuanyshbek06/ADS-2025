#include <bits/stdc++.h>
using namespace std;

vector<int> z_function(const string& s) {
    int n = (int)s.size();
    vector<int> z(n);
    int l = 0, r = 0;
    for (int i = 1; i < n; i++) {
        if (i <= r) z[i] = min(r - i + 1, z[i - l]);
        while (i + z[i] < n && s[z[i]] == s[i + z[i]]) z[i]++;
        if (i + z[i] - 1 > r) l = i, r = i + z[i] - 1;
    }
    return z;
}

int main() {
    string s;
    cin >> s;
    int n = (int)s.size();
    auto z = z_function(s);

    long long cnt = 0;
    for (int L = 2; L < n; L += 2) {   
        int half = L / 2;
        if (z[half] >= half) cnt++;      
    }
    cout << cnt << "\n";
    return 0;
}
