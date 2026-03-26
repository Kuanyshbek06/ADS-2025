#include <iostream>
#include <vector>
using namespace std;
int main(){
    int m;
    cin >> m;
    vector<int> arr(m);
    for(int i = 0; i<m;i++){
        cin>>arr[i];
    }
    int x;
    cin>>x;
    for(int i = 0;i<arr.size();i++){
        if(arr[i]==x) {
            cout<<"Yes";
            return 0;
                
        }
    }
    cout<<"No";
}