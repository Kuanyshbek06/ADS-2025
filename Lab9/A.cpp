#include <bits/stdc++.h>
using namespace std;

int main() {
    string A, B;
    cin >> A >> B;

    string repeated = A;
    int count = 1;

    
    while (repeated.size() < B.size() + A.size()) {
        if (repeated.find(B) != string::npos) {
            cout << count << "\n";
            return 0;
        }
        repeated += A;
        count++;
    }

    
    if (repeated.find(B) != string::npos)
        cout << count << "\n";
    else
        cout << -1 << "\n";

    return 0;
}
