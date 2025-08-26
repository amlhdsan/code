#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define IOS ios::sync_with_stdio(0);cin.tie(0)
int main(){
    IOS;
    int T; if(!(cin>>T)) return 0;
    while(T--){
        int n; cin>>n;
        vector<vector<int>> g(n+1);
        for(int i=0,u,v;i<n-1;i++){
            cin>>u>>v;
            g[u].push_back(v);
            g[v].push_back(u);
        }
        if(n<=2){ cout << -1 << '\n'; continue; }
        vector<unordered_set<int>> adj(n+1);
        for(int i=1;i<=n;i++){
            for(int v:g[i]) adj[i].insert(v);
        }
        queue<int> q;
        for(int i=1;i<=n;i++) if((int)adj[i].size()>2) q.push(i);
        vector<tuple<int,int,int>> ops;
        while(!q.empty()){
            int b = q.front(); q.pop();
            if((int)adj[b].size()<=2) continue;
            auto it = adj[b].begin();
            int a = *it; ++it;
            int c = *it;
            // collect neighbors to move (all except a and c)
            vector<int> tomove;
            for(int x: adj[b]) if(x!=a && x!=c) tomove.push_back(x);
            for(int d: tomove){
                adj[b].erase(d);
                adj[d].erase(b);
                // attach d to c
                if(adj[c].find(d)==adj[c].end()){
                    adj[c].insert(d);
                    adj[d].insert(c);
                }
            }
            ops.emplace_back(a,b,c);
            if((int)adj[c].size()>2) q.push(c);
            if((int)adj[b].size()>2) q.push(b);
        }
        if(ops.empty()) cout<<-1<<'\n';
        else{
            auto [a,b,c] = ops[0];
            cout<<a<<' '<<b<<' '<<c<<'\n';
        }
    }
    return 0;
}