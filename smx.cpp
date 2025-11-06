/*
# P5490 【模板】扫描线 & 矩形面积并

## 题目描述

求 $n$ 个四边平行于坐标轴的矩形的面积并。

## 输入格式

第一行一个正整数 $n$。

接下来 $n$ 行每行四个非负整数 $x_1, y_1, x_2, y_2$，表示一个矩形的四个端点坐标为 $(x_1, y_1),(x_1, y_2),(x_2, y_2),(x_2, y_1)$。

## 输出格式

一行一个正整数，表示 $n$ 个矩形的并集覆盖的总面积。

## 输入输出样例 #1

### 输入 #1

```
2
100 100 200 200
150 150 250 255
```

### 输出 #1

```
18000
```

## 说明/提示

对于 $20\%$ 的数据，$1 \le n \le 1000$。  
对于 $100\%$ 的数据，$1 \le n \le {10}^5$，$0 \le x_1 < x_2 \le {10}^9$，$0 \le y_1 < y_2 \le {10}^9$。

Updated on 4.10 by Dengduck（口胡） \& yummy（实现）：增加了一组数据。*/

#include <bits/stdc++.h>
using namespace std;

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