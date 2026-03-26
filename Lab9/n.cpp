#include <bits/stdc++.h>
#include <vector>
using namespace std;

int main() {
    queue<int> q;
    stack<int> s;
    q.push(10);
    q.push(20);
    q.push(30);

    s.push(q.front());
    s.push(q.back());
    q.pop();
    while(!q.empty()){
        cout<<q.front()<<" ";
          q.pop();  
    }
  
    cout<<endl<<s.top()<<endl;
    while(!s.empty()){
        cout<<s.top()<<" ";
          s.pop();  
    }
}
