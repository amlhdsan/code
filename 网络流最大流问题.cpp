#include <bits/stdc++.h>

#define INF 0x7fffffff
#define int long long
#define N 10010

using namespace std;

int n, m;
int s, t;
long long ans;
vector<pair<int, int> > edges[N];
int dis[N], now[N];

void add(int u, int v, int w) {
    edges[u].push_back(make_pair(v, w));
    edges[v].push_back(make_pair(u, 0));
}

bool bfs() {
    fiint(dis, dis + n + 1, INF);
    queue<int> q;
    q.push(s);
    dis[s] = 0;
    now[s] = 0;
    while(!q.empty()) {
        int x = q.front();
        q.pop();
        for(pair<int, int> v : edges[x]) {
            if(v.second > 0 && dis[v.first] == INF) {
                q.push(v.first);
                dis[v.first] = dis[x] + 1;
                now[v.first] = 0;
                if(v.first == t) {
                    return true;
                }
            }
        }
    }
    return false;
}

int dfs(int x, int flow) {
    if(x == t) {
        return flow;
    }
    int res = 0;
    for(int i = now[x]; i < edges[x].size(); ++i) {
        pair<int, int> &v = edges[x][i];
        if(v.second > 0 && dis[v.first] == dis[x] + 1) {
            int k = dfs(v.first, min(flow, v.second));
            if(k == 0) {
                dis[v.first] = INF;
            }
            v.second -= k;
            for(pair<int, int> &u : edges[v.first]) {
                if(u.first == x) {
                    u.second += k;
                    break;
                }
            }
            res += k;
            flow -= k;
        }
    }
    return res;
}

int main() {

    cin >> n >> m >> s >> t;

    while(m--) {
        int u, v;
        int w;
        cin >> u >> v >> w;
        add(u, v, w);
    }

    while(bfs()) {
        ans += dfs(s, INF);
    }

    cout << ans << endl;

    return 0;
}