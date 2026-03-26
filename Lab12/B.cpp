#include <bits/stdc++.h>
using namespace std;

const long long INF = 4e18;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<vector<pair<int,int>>> g(n+1);
    while(m--){
        int u,v,c;
        cin>>u>>v>>c;
        g[u].push_back({v,c});
        g[v].push_back({u,c});
    }

    auto dijkstra = [&](int s){
        vector<long long> d(n+1, INF);
        d[s] = 0;
        priority_queue<pair<long long,int>, vector<pair<long long,int>>, greater<>> pq;
        pq.push({0,s});
        while(!pq.empty()){
            auto [dist,v] = pq.top(); pq.pop();
            if(dist != d[v]) continue;
            for(auto &[to,w]: g[v]){
                if(d[to] > d[v]+w){
                    d[to] = d[v]+w;
                    pq.push({d[to],to});
                }
            }
        }
        return d;
    };

    int s,a,b,f;
    cin>>s>>a>>b>>f;

    auto ds = dijkstra(s);
    auto da = dijkstra(a);
    auto db = dijkstra(b);

    long long ans = INF;
    ans = min(ans, ds[a] + da[b] + db[f]);
    ans = min(ans, ds[b] + db[a] + da[f]);

    cout << (ans >= INF ? -1 : ans);
}
