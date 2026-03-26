#include <bits/stdc++.h>
using namespace std;

vector<int> prefix_function(string& s) { 
    vector<int> pi(s.size());
    for (int i = 1; i < (int)s.size(); ++i) {
        int j = pi[i - 1];
        while (j > 0 && s[j] != s[i])
            j = pi[j - 1];
        if (s[i] == s[j]) pi[i] = j + 1;
    }
    return pi;
}

int main() {
    string text, pattern;
    cin >> text >> pattern;  

    string combined = pattern + "#" + text;
    vector<int> pi = prefix_function(combined);

    vector<int> positions;
    for (int i = 0; i < (int)pi.size(); i++) {
        if (pi[i] == (int)pattern.size()) {
            int pos = i - 2 * (int)pattern.size(); 
            positions.push_back(pos + 1);          
        }
    }

    cout << positions.size() << "\n";
    for (int p : positions)
        cout << p << " ";
}
