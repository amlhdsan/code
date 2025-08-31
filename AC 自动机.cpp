#include <bits/stdc++.h>

#define N 200010
#define LEN 2000010
#define SIZE 200010

using namespace std;

int n;
char s[LEN];
int idx[N];

namespace AC {
    struct node {
        int son[26];
        int ans;
        int fail;
        int du;
        int idx;

        void init() {
            memset(son, 0, sizeof(son));
            ans = fail = idx = 0;
        }
    }tree[SIZE];

    int tot, ans[N], pidx;

    void init() {
        tot = pidx = 0;
        tree[0].init();
    }

    void insert(char s[], int &idx) {
        int u = 0;
        for(int i = 1; s[i]; ++i) {
            int &son = tree[u].son[s[i] - 'a'];
            if(!son) {
                son = ++tot;
                tree[son].init();
            }
            u = son;
        }
        if(!tree[u].idx) {
            tree[u].idx = ++pidx;
        }
        idx = tree[u].idx;
    }

    void build() {
        queue<int> q;

        for(int i = 0; i < 26; ++i) {
            if(tree[0].son[i]) {
                q.push(tree[0].son[i]);
            }
        }

        while(!q.empty()) {
            int u = q.front();
            q.pop();
            for(int i = 0; i < 26; ++i) {
                if(tree[u].son[i]) {
                    tree[tree[u].son[i]].fail = tree[tr[u].fail].son[i];
                    tree[tree[tr[u].fail].son[i]].du++;
                    q.push(tree[u].son[i]);
                }
                else {
                    tree[u].son[i] = tree[tree[u].fail].son[i];
                }
            }
        }
    }

    void qry(char t[]) {
        int u = 0;
        for(int i = 1; t[i]; ++i) {
            u = tree[u].son[t[i] - 'a'];  // 转移
            tr[u].ans++;
        }
    }
    
    void speed {
        
    }

    void topu() {
        queue<int> q;
        for(int i = 0; i <= tot; i++)
            if(tree[i].du == 0) 
                q.push(i);
        while(!q.empty()) {
            int u = q.front();
            q.pop();
            ans[tree[u].idx] = tree[u].ans;
            int v = tree[u].fail;
            tree[v].ans += tree[u].ans;
            if(!--tree[v].du) 
                q.push(v);
        }
    }
}

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

int main() {



    return 0;
}