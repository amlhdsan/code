#include <iostream>
#include <vector>
#include <numeric>
#include <queue>

using namespace std;

long long power(long long base, long long exp) {
    long long res = 1;
    base %= 998244353;
    while (exp > 0) {
        if (exp % 2 == 1) res = (res * base) % 998244353;
        base = (base * base) % 998244353;
        exp /= 2;
    }
    return res;
}

void solve() {
    int n, m;
    long long V;
    cin >> n >> m >> V;
    vector<long long> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    vector<vector<int>> adj(n);
    vector<int> deg(n, 0);
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        --u; --v;
        adj[u].push_back(v);
        adj[v].push_back(u);
        deg[u]++;
        deg[v]++;
    }

    // 1. Find cycle vertices (2-core)
    vector<int> current_deg = deg;
    queue<int> q;
    vector<bool> is_tree_vertex(n, false);
    for (int i = 0; i < n; ++i) {
        if (current_deg[i] <= 1) {
            q.push(i);
            is_tree_vertex[i] = true;
        }
    }

    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int v : adj[u]) {
            if (!is_tree_vertex[v]) {
                current_deg[v]--;
                if (current_deg[v] <= 1) {
                    q.push(v);
                    is_tree_vertex[v] = true;
                }
            }
        }
    }
    vector<bool> is_cycle_vertex(n);
    for(int i=0; i<n; ++i) is_cycle_vertex[i] = !is_tree_vertex[i];
    
    // 2. Check for bipartiteness
    bool is_bipartite = true;
    vector<int> color(n, 0);
    if (n > 0) {
        queue<int> bq;
        bq.push(0);
        color[0] = 1;
        while(!bq.empty()){
            int u = bq.front();
            bq.pop();
            for(int v : adj[u]){
                if(color[v] == 0){
                    color[v] = -color[u];
                    bq.push(v);
                } else if (color[v] == color[u]){
                    is_bipartite = false;
                    break;
                }
            }
            if(!is_bipartite) break;
        }
    }

    // 3. Count ways
    long long k_T_U = 0;
    long long ways_C = 0;
    
    long long required_weight = -1;
    bool possible = true;
    for (int i = 0; i < n; ++i) {
        if (is_cycle_vertex[i] && a[i] != -1) {
            if (required_weight == -1) {
                required_weight = a[i];
            } else if (required_weight != a[i]) {
                possible = false;
                break;
            }
        }
    }

    if (!possible) {
        ways_C = 0;
    } else {
        if (required_weight != -1) {
            if (!is_bipartite && required_weight != 0) {
                ways_C = 0;
            } else {
                ways_C = 1;
            }
        } else {
            if (!is_bipartite) {
                ways_C = 1;
            } else {
                ways_C = V % 998244353;
            }
        }
    }
    
    for (int i = 0; i < n; ++i) {
        if (!is_cycle_vertex[i] && a[i] == -1) {
            k_T_U++;
        }
    }

    long long ways_T = power(V, k_T_U);
    long long total_ways = (ways_C * ways_T) % 998244353;
    
    cout << total_ways << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NUint);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}