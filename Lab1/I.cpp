#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    string s;
    cin >> n >> s;

    queue<int> S, K;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == 'S') S.push(i);
        else K.push(i);
    }

    while (!S.empty() && !K.empty()) {
        int idS = S.front(); S.pop();
        int idK = K.front(); K.pop();

        if (idS < idK) S.push(idS + n);
        else K.push(idK + n);
    }

    if (S.empty()) cout << "KATSURAGI";
    else cout << "SAKAYANAGI";
    return 0;
}
