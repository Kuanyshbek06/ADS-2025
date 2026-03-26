#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<long long> vc(n);
    for(int i = 0; i < n; i++){
        cin>>vc[i];
    }
    sort(vc.begin(),vc.end());
    vector<long long> pref(n + 1, 0);
    for (int i = 1; i <= n; i++)
        pref[i] = pref[i - 1] + vc[i - 1];

    int q;
    cin >> q;
    while (q--) {
        long long p;
        cin >> p;
        int pos = upper_bound(vc.begin(), vc.end(), p) - vc.begin();
        cout << pos << " " << pref[pos] << "\n";
    }
    return 0;

}