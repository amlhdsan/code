/*
# P3456 [POI 2007] GRZ-Ridges and Valleys

## 题目描述

**译自 POI 2007 Stage 2. Day 0「[Ridges and Valleys](https://szkopul.edu.pl/problemset/problem/rd6H05Dm8ME79sO3U9_f_ga_/site/?key=statement)」**

给定一个 $n \times n$ 的网格状地图，每个方格 $(i,j)$ 有一个高度 $w_{ij}$。如果两个方格有公共顶点，则它们是相邻的。

定义山峰和山谷如下：
* 均由地图上的一个连通块组成；
* 所有方格高度都相同；
* 周围的方格（即不属于山峰或山谷但与山峰或山谷相邻的格子）高度均大于山谷的高度，或小于山峰的高度。

求地图内山峰和山谷的数量。特别地，如果整个地图方格的高度均相同，则整个地图既是一个山谷，也是一个山峰。

## 输入格式

第一行一个整数 $n$ （$2 \le n \le 1000$），表示地图的大小。

接下来 $n$ 行每行 $n$ 个整数表示地图。第 $i$ 行有 $n$ 个整数 $w_{i1}, w_{i2}, \ldots, w_{in} (0 \le w_{ij} \le 1\ 000\ 000\ 000)$，表示地图第 $i$ 行格子的高度。

## 输出格式

输出一行两个整数，分别表示山峰和山谷的数量。

### 样例解释

![](https://cdn.luogu.com.cn/upload/image_hosting/yubj6du3.png)

![](https://cdn.luogu.com.cn/upload/image_hosting/7ct18655.png)

翻译来自于 [LibreOJ](https://loj.ac/p/2653)。

## 输入输出样例 #1

### 输入 #1

```
5
8 8 8 7 7
7 7 8 8 7
7 7 7 7 7
7 8 8 7 8
7 8 8 8 8
```

### 输出 #1

```
2 1
```

## 输入输出样例 #2

### 输入 #2

```
5
5 7 8 3 1
5 5 7 6 6
6 6 6 2 8
5 7 2 5 8
7 1 0 1 7
```

### 输出 #2

```
3 3
```
*/

#include <bits/stdc++.h>
using namespace std;

int n;
int mp[1010][1010];
int mp1[1010][1010];
int mp2[1010][1010];

bool tag1[1010][1010];
bool tag2[1010][1010];

int ans1 = 0, ans2 = 0;

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
}

int main() {

    n = read();

    int maxxx = -1, minnn = 0x7fffffff;

    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= n; ++j) {
            mp[i][j] = read();
            maxxx = max(maxxx, mp[i][j]);
            minnn = min(minnn, mp[i][j]);
            mp1[i][j] = mp[i][j];
            mp2[i][j] = mp[i][j];
        }
    }

    if(maxxx == minnn) {
        write(1);
        putchar(' ');
        write(1);
        putchar('\n');
        return 0;
    }

    // mp1 : 山峰(周围设置为山谷)

    for(int i = 0; i <= n + 1; ++i) {
        mp1[0][i] = -1;
        mp1[n + 1][i] = -1;
        mp1[i][0] = -1;
        mp1[i][n + 1] = -1;
    }

    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= n; ++j) {
            if(!tag1[i][j]) {
                queue<pair<int, int>> q;
                q.push({i, j});
                tag1[i][j] = true;
                bool t1 = true;
                vector<pair<int, int>> k;
                k.push_back({i, j});
                while(!q.empty()) {
                    auto [x, y] = q.front();
                    q.pop();
                    int dx[] = {0, 0, 1, -1, 1, 1, -1, -1};
                    int dy[] = {1, -1, 0, 0, 1, -1, 1, -1};
                    for(int t = 0; t < 8; ++t) {
                        int nx = x + dx[t];
                        int ny = y + dy[t];
                        if(nx >= 0 && nx <= n + 1 && ny >= 0 && ny <= n + 1) {
                            if(mp1[nx][ny] > mp1[i][j]) {
                                t1 = false;
                            } 
                            else if(mp1[nx][ny] == mp1[i][j] && !tag1[nx][ny]) {
                                tag1[nx][ny] = true;
                                q.push({nx, ny});
                                k.push_back({nx, ny});
                            }
                        }
                    }
                }
                if(t1) {
                    ans1++;
                }
            }
        }
    }

    write(ans1);
    putchar(' ');

    // mp2 : 山谷(周围设置为山峰)

    for(int i = 0; i <= n + 1; ++i) {
        mp2[0][i] = 0x7fffffff;
        mp2[n + 1][i] = 0x7fffffff;
        mp2[i][0] = 0x7fffffff;
        mp2[i][n + 1] = 0x7fffffff;
    }

    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= n; ++j) {
            if(!tag2[i][j]) {
                queue<pair<int, int>> q;
                q.push({i, j});
                tag2[i][j] = true;
                bool t2 = true;
                vector<pair<int, int>> k;
                k.push_back({i, j});
                while(!q.empty()) {
                    auto [x, y] = q.front();
                    q.pop();
                    int dx[] = {0, 0, 1, -1, 1, 1, -1, -1};
                    int dy[] = {1, -1, 0, 0, 1, -1, 1, -1};
                    for(int t = 0; t < 8; ++t) {
                        int nx = x + dx[t];
                        int ny = y + dy[t];
                        if(nx >= 0 && nx <= n + 1 && ny >= 0 && ny <= n + 1) {
                            if(mp2[nx][ny] < mp2[i][j]) {
                                t2 = false;
                            } 
                            else if(mp2[nx][ny] == mp2[i][j] && !tag2[nx][ny]) {
                                tag2[nx][ny] = true;
                                q.push({nx, ny});
                                k.push_back({nx, ny});
                            }
                        }
                    }
                }
                if(t2) {
                    ans2++;
                }
            }
        }
    }

    writeln(ans2);

    return 0;
}