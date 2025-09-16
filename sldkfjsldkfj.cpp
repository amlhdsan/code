/*# CF632D Longest Subsequence

## 题目描述

给定有 $n$ 个元素的数组 $a$ 和数字 $m$。记 LCM 为 $l$ 。找出使 $l \le m$ 的 $a$ 的最长子序列。

定义 $a$ 的子序列为通过删除 $a$ 中的一些元素得到的数组。允许删除 $0$ 个元素或所有元素。

空数组的 LCM 等于 $1$。

## 输入格式

第一行包含两个整数 $n$ 和 $m$ ( $ 1 \le n,m \le 10^{6} $ ) — 数组 $a$ 的大小和题目描述中的参数。

第二行包含 n 个整数 $ a_{i} $ ( $ 1 \le a_{i} \le 10^{9} $ ) — $a$ 的元素。

## 输出格式

第一行打印两个整数 $ l $ 和 $ k_{\max} $ ( $ 1 \le l \le m,0 \le k_{\max} \le n $ ) — LCM 的值和最优子序列中的元素数量。

第二行打印 $ k_{\max} $ 个整数 — 按升序排序输出元素。

请注意，您可以找到并打印任何具有最大长度的子序列。

## 输入输出样例 #1

### 输入 #1

```
7 8
6 2 9 2 7 2 3
```

### 输出 #1

```
6 5
1 2 4 6 7
```

## 输入输出样例 #2

### 输入 #2

```
6 4
2 2 2 3 3 3
```

### 输出 #2

```
2 3
1 2 3
```
*/

#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    if(!(cin >> n >> m)) return 0;
    vector<int> a(n+1);
    for(int i=1;i<=n;i++) cin >> a[i];
    vector<int> freq(m+1);
    for(int i=1;i<=n;i++) if(a[i] <= m) freq[a[i]]++;
    vector<int> cnt(m+1);
    for(int x=1;x<=m;x++){
        if(freq[x]==0) continue;
        for(int d=x; d<=m; d+=x) cnt[d] += freq[x];
    }
    int best_d = 1, best_cnt = 0;
    for(int d=1; d<=m; d++){
        if(cnt[d] > best_cnt){
            best_cnt = cnt[d];
            best_d = d;
        }
    }
    cout << best_d << " " << best_cnt << "\n";
    if(best_cnt == 0){
        cout << "\n";
        return 0;
    }
    bool first = true;
    for(int i=1;i<=n;i++){
        if(best_d % a[i] == 0){
            if(!first) cout << " ";
            cout << i;
            first = false;
        }
    }
    cout << "\n";
    return 0;
}