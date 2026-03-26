#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<long long> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    long long left = 1;                     
    long long right = *max_element(a.begin(), a.end()); 

    while (left < right) {
        long long mid = (left + right) / 2;
        long long flights = 0;

        for (long long x : a) {
            flights += (x + mid - 1) / mid; 
            if (flights > k) break;         
        }

        if (flights <= k)
            right = mid; 
        else
            left = mid + 1; 
    }

    cout << left << "\n";
    return 0;
}
