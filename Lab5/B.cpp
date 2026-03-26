#include <bits/stdc++.h>
using namespace std;
int main(){
    priority_queue<long long >pq;
    long long n,x;
    cin>> n;
    for(int i = 0; i <n;i++ ){
        cin>>x;
        pq.push(x);
    }
    while(pq.size()>1){
        int u = pq.top();pq.pop();
        int v = pq.top();pq.pop();
        if(u!=v) pq.push(abs(v-u));
    }
    if(pq.size()==0) cout<< 0;
    else cout<<pq.top();
    return 0;

}