#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    unordered_map<int, int> freq;
    for (int x : arr) {
        freq[x]++;
    }

    
    int maxFreq = 0;
    for (auto &p : freq) {
        if (p.second > maxFreq) {
            maxFreq = p.second;
        }
    }

    vector<int> modes;
    for (auto &p : freq) {
        if (p.second == maxFreq) {
            modes.push_back(p.first);
        }
    }

    sort(modes.rbegin(), modes.rend());

    for (int x : modes) {
        cout << x << " ";
    }

    return 0;
}
