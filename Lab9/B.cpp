#include <bits/stdc++.h>
using namespace std;
vector <int> prefix_function(string& s){ 
    vector <int> pi(s.size());
    for(int i = 1; i<(int)s.size();++i){
        int j=pi[i-1];
        while(j>0 && s[j] != s[i]){
            j=pi[j-1];
        }
        if(s[i]==s[j]) pi[i]=j+1;
        
    }
    return pi;
}
  int kmp(string& s,string& t){
    t= s + '#' + t;
    int count=0;
    vector<int> pi=prefix_function(t);
    for(int i = 0;i<(int)pi.size();i++){
        if(pi[i] == s.size()) count++;
    }
    return count;
}
int main(){
    string s,t;
    int k;
    cin>>s>>k;
    cin>>t;
    int count = kmp(s,t);
    if(count>=k) cout<<"YES";
    else cout<<"NO";
}
