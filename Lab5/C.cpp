#include <bits/stdc++.h>
using namespace std;
int main(){
    priority_queue<long long , vector<long long> >pq;
    long long n,x,k, sum=0;
    cin>>n>>k;
    for(int i = 0; i < n; i++){
        cin>>x;
        pq.push(x);
    }
      while(k--){
        sum += pq.top();
        int u = pq.top();
        pq.pop();
        pq.push(u - 1);
    }
    
    cout << sum;
    return 0;
}