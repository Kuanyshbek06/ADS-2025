#include <bits/stdc++.h>
using namespace std;

bool isVowel(char c) {
    c = tolower(c);
    return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
}

int main() {
    int n;
    cin >> n;
    string s;
    cin >> s;

    vector<char> vowels, consonants;

    for (char c : s) {
        if (isVowel(c)) vowels.push_back(c);
        else consonants.push_back(c);
    }

    sort(vowels.begin(), vowels.end());
    sort(consonants.begin(), consonants.end());


    for (char v : vowels) cout << v;
    for (char c : consonants) cout << c;

    cout << endl;
    return 0;
}

