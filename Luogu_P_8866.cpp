#include <bits/stdc++.h>

#define N 305
#define M 2000010
#define K 1005

using namespace std;

int a[M], id[K];
int n, m, k, sp;
queue<int> q;
deque<int> dq[N];
vector<pair<int, int>> ans;

inline int read() {
    int x = 0, f = 1;
    char ch = getchar();
    while (ch < '0' || ch > '9') {
        if (ch == '-') f = -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9') {
        x = (x << 3) + (x << 1) + (ch ^ 48);
        ch = getchar();
    }
    return x * f;
}

inline void write(int x) {
    if (x < 0) {
        putchar('-');
        x = -x;
    }
    if (x > 9) write(x / 10);
    putchar(x % 10 + '0');
}

inline void writeln(int x) {
    write(x);
    putchar('\n');
}

void add(int p) {
    ans.push_back(make_pair(p, 0));
}

void mov(int p1, int p2) {
    ans.push_back(make_pair(p1, p2));
}

void pushdown(int p1, int p2) {

}

void 

void clr() {
    while (!q.empty()) q.pop();
    for (int i = 1; i <= k; i++) id[i] = 0;
    ans.clear();
    sp = n;
}

int sol(int x) {
    if (id[x]) {
        int p = id[x];
        if (dq[p].back() == x) {
            id[x] = 0;
            dq[p].pop_back();
            add(p);
            q.push(p);
        } else if (dq[p].front() == x) {
            id[x] = 0;
            dq[p].pop_front();
            add(sp);
            mov(p, sp);
            q.push(p);
        }
    }
    
    else {
        if (q.empty()) {
            return 0;
        } else {
            int p = q.front();
            dq[p].push_back(x);
            q.pop();
            id[x] = p;
            add(p);
        }
    }
    return 1;
}

int wrk(int pos) {
    int t = pos;
    pos++;
    while (id[a[pos]] && dq[id[a[pos]]].back() == a[pos]) pos++;
    if (a[pos] == a[t]) {
        add(sp);
        for (int i = t + 1; i < pos; i++) sol(a[i]);
        add(sp);
        return pos;
    }
    int cnt = 0, idx = id[a[pos]];
    for (int i = t; i < pos; i++) if (id[a[i]] == idx) cnt++;
    int p = id[a[pos]];
    int y = dq[p].back();
    if (cnt & 1) {
        add(sp);
        dq[sp].push_back(a[t]);
        for (int i = t + 1; i < pos; i++) {
            if (a[i] == y) add(p);
            else sol(a[i]);
        }
        add(p);
        dq[p].clear();
        id[a[pos]] = id[y] = 0;
        id[a[t]] = sp;
        q.push(sp);
        sp = p;
    } else {
        add(p);
        dq[p].push_back(a[t]);
        for (int i = t + 1; i < pos; i++) {
            if (a[i] == y) add(sp);
            else sol(a[i]);
        }
        add(sp);
        mov(p, sp);
        dq[p].pop_front();
        id[a[pos]] = 0;
        id[a[t]] = p;
    }
    return pos;
}

int main() {
    int T = read();
    while (T--) {
        n = read();
        m = read();
        k = read();
        clr();
        for (int i = 1; i <= m; i++) a[i] = read();
        for (int i = 1; i < n; i++) {
            q.push(i);
            q.push(i);
        }
        for (int i = 1; i <= m; i++) {
            int x = a[i];
            if (sol(x)) continue;
            int p = wrk(i);
            i = p;
        }
        printf("%d\n", (int)ans.size());
        for (auto v : ans) {
            if (v.second) {
                printf("2 %d %d\n", min(v.first, v.second), max(v.first, v.second));
            } else {
                printf("1 %d\n", v.first);
            }
        }
    }
    return 0;
}