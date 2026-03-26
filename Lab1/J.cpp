#include <bits/stdc++.h>
using namespace std;

int main() {
    char c;
    int s;
    deque<int> dq;

    while (cin >> c) {
        if (c == '+') {
            cin >> s;
            dq.push_front(s);
        }
        else if (c == '-') {
            cin >> s;
            dq.push_back(s);
        }
        else if (c == '*') {
            if (dq.empty()) {
                cout << "error\n";
            } else if (dq.size() == 1) {
                cout << dq.front() + dq.front() << "\n";
                dq.pop_front();
            } else {
                cout << dq.front() + dq.back() << "\n";
                dq.pop_front();
                dq.pop_back();
            }
        }
        else if (c == '!') {
            break;
        }
    }

    return 0;
}
