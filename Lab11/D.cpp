#include <bits/stdc++.h>
using namespace std;

int main(){

    int n;
    cin>>n;

    vector<vector<int>> a(n, vector<int>(n));
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            cin>>a[i][j];

    const int INF = 1e9;
    vector<int> dist(n, INF);
    vector<int> used(n, 0);

    dist[0]=0;
    long long ans=0;

    for(int i=0;i<n;i++){
        int v=-1;
        for(int j=0;j<n;j++)
            if(!used[j] && (v==-1 || dist[j]<dist[v]))
                v=j;
        used[v]=1;
        ans+=dist[v];

        for(int u=0;u<n;u++){
            if(!used[u] && a[v][u]<dist[u])
                dist[u]=a[v][u];
        }
    }

    cout<<ans;
}

