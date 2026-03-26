#include <bits/stdc++.h>
using namespace std;

struct Date {
    int d, m, y;
    string s; 
};

int main() {
    int n;
    cin >> n;

    vector<Date> dates(n);
    for (int i = 0; i < n; i++) {
        cin >> dates[i].s;

        dates[i].d = stoi(dates[i].s.substr(0, 2));
        dates[i].m = stoi(dates[i].s.substr(3, 2));
        dates[i].y = stoi(dates[i].s.substr(6, 4));
    }


    sort(dates.begin(), dates.end(), [](Date a, Date b) {
        if (a.y != b.y) return a.y < b.y;
        if (a.m != b.m) return a.m < b.m;
        return a.d < b.d;
    });

    for (auto &dt : dates)
        cout << dt.s << endl;

    return 0;
}
