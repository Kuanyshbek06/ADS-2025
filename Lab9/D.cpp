#include <bits/stdc++.h>
using namespace std;

vector<int> prefix_function(const string &s) {
    int n = s.size();
    vector<int> pi(n);
    for (int i = 1; i < n; i++) {
        int j = pi[i - 1];
        while (j > 0 && tolower(s[i]) != tolower(s[j]))
            j = pi[j - 1];
        if (tolower(s[i]) == tolower(s[j])) pi[i] = j+1;
    }
    return pi;
}

int main() {
    string prev;
    int n;
    cin >> prev >> n;
    vector<string> cities(n);
    for (int i = 0; i < n; i++) cin >> cities[i];

    int maxMatch = 0;
    vector<int> match(n);

    for (int i = 0; i < n; i++) {
        string combined = cities[i] + "#" + prev;
        vector<int> pi = prefix_function(combined);
        match[i] = pi.back();
        maxMatch = max(maxMatch, match[i]);
    }

    vector<string> result;
    for (int i = 0; i < n; i++)
        if (match[i] == maxMatch && maxMatch > 0)
            result.push_back(cities[i]);

    cout << result.size() << "\n";
    for (auto &x : result)
        cout << x << "\n";

    return 0;
}

