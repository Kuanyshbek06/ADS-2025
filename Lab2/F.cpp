#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> vc(n);
    for (int i = 0; i < n; i++) cin >> vc[i];

    int k, m;              
    cin >> k >> m;

    vc.insert(vc.begin() + m, k);

    for (int x : vc) cout << x << ' ';
}
