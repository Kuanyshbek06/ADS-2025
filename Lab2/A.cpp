#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int x;
    cin >> x;

    int bestIndex = 0;
    int bestDiff = abs(arr[0] - x);

    for (int i = 1; i < n; i++) {
        int diff = abs(arr[i] - x);
        if (diff < bestDiff) {
            bestDiff = diff;
            bestIndex = i;
        }
    }

    cout << bestIndex;
    return 0;
}
