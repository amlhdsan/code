/*
# P6708 [CCC 2020] Josh's Double Bacon Deluxe

## 题目背景

Josh 和 $N-1$ 个人去吃汉堡。

## 题目描述

这个汉堡店共有 $M$ 种汉堡。

第 $i$ 个人最喜欢吃的汉堡为第 $b_i$ 种汉堡。

这 $N$ 个人都会选他最喜欢吃的汉堡。

现在，这 $N$ 个人排队去取汉堡，不幸的是，第一个人忘记了他最喜欢的汉堡，于是他随便拿了一个汉堡。

接下来的 $N-2$ 个人会按如下规则拿汉堡：
- 如果有他最喜欢的汉堡，就直接拿走。
- 否则，他会随便拿一个。

您需要求出，**排在最后**的 Josh 拿到他最喜欢汉堡的概率。

## 输入格式

第一行为一个整数 $N$。

接下来 $N$ 行，一行一个整数 $b_i$。

## 输出格式

一行一个小数，表示**排在最后**的 Josh 拿到他最喜欢汉堡的概率。

## 输入输出样例 #1

### 输入 #1

```
3
1 2 3

```

### 输出 #1

```
0.5
```

## 输入输出样例 #2

### 输入 #2

```
7
1 2 3 1 1 2 3
```

### 输出 #2

```
0.57142857
```

## 说明/提示

#### 样例 1 解释
| 第一个人的选择 | 第二个人的选择 | Josh 的选择 | 概率 |
| :----------: | :----------: | :----------: | :----------: |
| $1$ | $2$ | $3$ | $\frac{1}{3}$ |
| $2$ | $1$ | $3$ | $\frac{1}{3}\times \frac{1}{2}=\frac{1}{6}$ |
| $2$ | $3$ | $1$ | $\frac{1}{6}$ |
| $3$ | $2$ | $1$ | $\frac{1}{3}$ |

Josh 拿到他最喜欢汉堡的概率为 $\frac{1}{3}+\frac{1}{6}=\frac{1}{2}$。

#### SPJ 计分标准
设正确答案为 $C$，你的答案为 $P$，若 $\lvert P-C\rvert <10^{-6}$，则您得该测试点的满分，否则，您得零分。

#### 子任务
**本题采用捆绑测试，且本题的 Subtask 分数有微调。**
- Subtask 1（$27$ 分）：保证 $N\le 10^5$，$M\le 10^3$。
- Subtask 2（$33$ 分）：保证 $M\le 10^3$。
- Subtask 3（$40$ 分）：无特殊限制。

对于 $100\%$ 的数据，保证 $3\le N\le 10^6$，$1\le b_i\le M\le 5\times 10^5$。

#### 说明
本题译自 [Canadian Computing Competition](https://cemc.uwaterloo.ca/resources/past-contests?contest_category=29) [2020 Senior](https://cemc.uwaterloo.ca/sites/default/files/documents/2020/seniorEF.pdf) T5 Josh's Double Bacon Deluxe。
*/
#include <bits/stdc++.h>

#define N 1000100

using namespace std;

int n;
int b[N];

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

inline void build() {
    
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

    n = read();

    for(int i = 1; i <= n; ++i) {
        b[i] = read();
    }

    for()

    return 0;
}