/*
# P3884 [JLOI2009] 二叉树问题

## 题目描述

如下图所示的一棵二叉树的深度、宽度及结点间距离分别为：

- 深度：$4$
- 宽度：$4$
- 结点 8 和 6 之间的距离：$8$
- 结点 7 和 6 之间的距离：$3$

其中宽度表示二叉树上同一层最多的结点个数，节点 $u, v$ 之间的距离表示从 $u$ 到 $v$ 的最短有向路径上向根节点的边数的两倍加上向叶节点的边数。

![](https://cdn.luogu.com.cn/upload/pic/6843.png)

给定一颗以 1 号结点为根的二叉树，请求出其深度、宽度和两个指定节点 $x, y$ 之间的距离。

## 输入格式

第一行是一个整数，表示树的结点个数 $n$。  
接下来 $n - 1$ 行，每行两个整数 $u, v$，表示树上存在一条连接 $u, v$ 的边。  
最后一行有两个整数 $x, y$，表示求 $x, y$ 之间的距离。

## 输出格式

输出三行，每行一个整数，依次表示二叉树的深度、宽度和 $x, y$ 之间的距离。

## 输入输出样例 #1

### 输入 #1

```
10                                
1 2                            
1 3                            
2 4
2 5
3 6
3 7
5 8
5 9
6 10
8 6

```

### 输出 #1

```
4
4
8
```

## 说明/提示

对于全部的测试点，保证 $1 \leq u, v, x, y \leq n \leq 100$，且给出的是一棵树。保证 $u$ 是 $v$ 的父结点。
*/
#include <bits/stdc++.h>

#define N 100005

using namespace std;

int n;
vector<int> e[N];
int dep[N];
int parent[N]; // store parent in tree
int num[N];

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

inline void bfs(int s) {
    queue<int> q;
    q.push(s);
    dep[s] = 1;
    parent[s] = 0; // root has no parent

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (int v : e[u]) {
            if (!dep[v]) {
                dep[v] = dep[u] + 1;
                parent[v] = u;
                q.push(v);
            }
        }
    }
}

inline int lca(int x, int y) {
    // climb deeper node up to same depth
    while (dep[x] > dep[y]) x = parent[x];
    while (dep[y] > dep[x]) y = parent[y];
    while (x && y && x != y) {
        x = parent[x];
        y = parent[y];
    }
    return x; // if tree guaranteed, x==y at root eventually
}

int main() {

    n = read();

    for(int i = 1; i < n; i++) {
        int u = read(), v = read();
        e[u].push_back(v);
        e[v].push_back(u);
    }

    // run BFS from root to compute depth/parent

    bfs(1);

    // 深度
    int ans = 0;
    for (int i = 1; i <= n; i++)
        ans = max(ans, dep[i]);
    writeln(ans);

    // 宽度：统计每层节点数
    for (int i = 1; i <= n; i++) {
        if (dep[i] > 0) num[dep[i]]++;
    }
    int md = 1;
    for (int i = 2; i <= n; i++) {
        if (num[i] > num[md]) {
            md = i;
        }
    }
    
    writeln(num[md]);

    int x = read(), y = read();

    writeln((dep[x] - dep[lca(x, y)]) * 2 + (dep[y] - dep[lca(x, y)]));
    return 0;
}