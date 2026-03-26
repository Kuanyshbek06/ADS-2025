#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<string> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    vector<string> uniqueNames;
    for (int i = 0; i < n; i++) {
        if (i == 0 || arr[i] != arr[i - 1]) {
            uniqueNames.push_back(arr[i]);
        }
    }

    reverse(uniqueNames.begin(), uniqueNames.end());

    cout << "All in all: " << uniqueNames.size() << endl;
    cout << "Students:" << endl;
    for (string &name : uniqueNames) {
        cout << name << endl;
    }

    return 0;
}
