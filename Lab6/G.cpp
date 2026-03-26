#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    map<string, string> oldToNew;  
    map<string, string> newToOld; 

    for (int i = 0; i < n; i++) {
        string oldNick, newNick;
        cin >> oldNick >> newNick;

    
        if (newToOld.count(oldNick)) {
            string original = newToOld[oldNick];
            oldToNew[original] = newNick;   
            newToOld.erase(oldNick);        
            newToOld[newNick] = original;   
        } else {
            oldToNew[oldNick] = newNick;
            newToOld[newNick] = oldNick;
        }
    }

    cout << oldToNew.size() << endl;
    for (auto &p : oldToNew)
        cout << p.first << " " << p.second << endl;

    return 0;
}
