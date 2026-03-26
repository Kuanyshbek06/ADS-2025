#include <bits/stdc++.h>
using namespace std;

int main() {
    queue<int> st1, st2;

    
    for (int i = 0; i < 5; i++) {
        int n;
        cin >> n;
        st1.push(n);
    }

    
    for (int i = 0; i < 5; i++) {
        int x;
        cin >> x;
        st2.push(x);
    }

    int moves = 0;

    while (!st1.empty() && !st2.empty() && moves <= 1000000) {
        moves++;
        int a = st1.front(); st1.pop();
        int b = st2.front(); st2.pop();

        if ((a == 0 && b == 9) || (a > b && !(a == 9 && b == 0))) {
            st1.push(a);
            st1.push(b);
        } else {
            st2.push(a);
            st2.push(b);
        }
    }

    if (moves > 1000000) {
        cout << "blin nichya";
    } else if (st1.empty()) {
        cout << "Nursik " << moves;
    } else {
        cout << "Boris " << moves;
    }

    return 0;
}
