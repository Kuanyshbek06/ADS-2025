#include <bits/stdc++.h>
using namespace std;
int main(){
    string s,t,ans1,ans2;
    cin>>s>>t;
    for(int i = 0; i <s.size(); i++){
        if(s[i]=='#'){
            ans1.pop_back();
        }
        else {ans1 += s[i];}
    }
    for(int i = 0; i <t.size();i++){
        if(t[i]=='#'){
            ans2.pop_back();
        }
        else{
            ans2+=t[i];
        }
    }
    if(ans1==ans2){
        cout<<"Yes";
    }
    else{
        cout<<"No";
    }
    return 0;
}
    