#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int n;
    cin >> n;
    vector<ll> h(n);
    for (int i = 0; i < n; ++i)
        cin >> h[i];

    string s;
    for (int i = 0; i < n; ++i) {
        ll diff = (i == 0 ? h[0] : h[i] - h[i - 1]);
        ll val = diff / (1LL << i);  
        s.push_back(char(val + 97));  
    }

    cout << s << "\n";
    return 0;
}
