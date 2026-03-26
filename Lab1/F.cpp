#include <bits/stdc++.h>
using namespace std;
bool isPrime(int x){
    if (x < 2) return false;
    for(int i = 2; x >= i*i; i++){
        if(x % i == 0) return false;

    }
    return true;
}  
int main(){
    int N;
    cin>>N;
    int count = 0; int number = 1;
    while(count<N){
        number++;
        if(isPrime(number)){
            count++;
        }
    }
    cout<<number;
    return 0;
}


