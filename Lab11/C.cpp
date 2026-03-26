#include <bits/stdc++.h>
using namespace std;

struct DSU{
    vector<int> p;
    DSU(int n){ p.resize(n+1); iota(p.begin(),p.end(),0); }
    int find(int x){ return p[x]==x?x:p[x]=find(p[x]); }
    bool unite(int a,int b){
        a=find(a); b=find(b);
        if(a==b) return false;
        p[b]=a;
        return true;
    }
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,m;
    cin>>n>>m;

    int x,y;
    cin>>x>>y;

    struct E{int a,b; long long w;};
    vector<E> e;

    while(m--){
        string t;
        int a,b,c;
        cin>>t>>a>>b>>c;
        long long w;
        if(t=="big") w=1LL*x*c;
        else if(t=="small") w=1LL*y*c;
        else w=1LL*min(x,y)*c;
        e.push_back({a,b,w});
    }

    sort(e.begin(),e.end(),[](auto&A,auto&B){return A.w<B.w;});

    DSU d(n);
    long long ans=0;
    for(auto &u:e)
        if(d.unite(u.a,u.b)) ans+=u.w;

    cout<<ans;
}
