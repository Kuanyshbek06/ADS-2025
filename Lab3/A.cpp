#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i = 0; i<n;i++){
        cin>>arr[i];

    }
    int a,b;
    cin>>a>>b;
    vector<vector<int>> vc(a, vector<int>(b)); 

    for(int i = 0;i<a;i++){
        for(int j = 0; j<b;j++){
            cin>>vc[i][j];
        }
    }
    for (int x : arr) {
    bool found = false;
    for (int i = 0; i <a && !found; i++) {
        for (int j = 0; j < b; j++) {
            if (vc[i][j] == x) {
                cout << i << " " << j << "\n";
                found = true;
                break;
            }
        }
    }
    if (!found) cout << -1 << "\n";
    }
    return 0;
}