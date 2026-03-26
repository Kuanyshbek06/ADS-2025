#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    bool prime = true;
    if (n < 2) prime = false;
    for(int i = 2; n >= i*i; i++){
        if(n % i == 0){
            prime = false;
            break;

        }

    }
    if (prime) cout << "YES";
    else cout <<"NO";
    return 0;
 
}

