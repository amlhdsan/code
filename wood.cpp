#include <bits/stdc++.h>

#define N 1000010
#define int long long
#define ls (p << 1)
#define rs (p << 1 | 1)
#define mid ((l + r) >> 1)

using namespace std;

const int mx = 2e9;

int n, k, c;
int a[N];
int b[N];
int tree[N << 2];
int lazy[N << 2];

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

inline void upd(int p) {
    tree[p] = tree[ls] + tree[rs];
}

inline void build(int p, int l, int r) {
    if(l == r) {
        tree[p] = b[l];
        return;
    }
    build(ls, l, mid);
    build(rs, mid + 1, r);
    upd(p);
}

inline void pushd(int p, int l, int r) {
    if(lazy[p] != 0) {
        tree[ls] += lazy[p] * (mid - l + 1);
        tree[rs] += lazy[p] * (r - (mid + 1) + 1);
        lazy[ls] += lazy[p];
        lazy[rs] += lazy[p];
        lazy[p] = 0;
    }
}

inline void mdf(int p, int l, int r, int ql, int qr, int x) {
    if(ql <= l && r <= qr) {
        tree[p] += x * (r - l + 1);
        lazy[p] += x;
        return;
    }
    pushd(p, l, r);
    if(ql <= mid) {
        mdf(ls, l, mid, ql, qr, x);
    }
    if(qr > mid) {
        mdf(rs, mid + 1, r, ql, qr, x);
    }
    upd(p);
}

inline int qry(int p, int l, int r, int ql, int qr) {
    if(ql <= l && r <= qr) {
        return tree[p];
    }
    pushd(p, l, r);
    int mxx = 0;
    if(ql <= mid) {
        mxx += qry(ls, l, mid, ql, qr);
    }
    if(qr > mid) {
        mxx += qry(rs, mid + 1, r, ql, qr);
    }
    return mxx;
}

// inline int check(int x) {
//     for(int i = 1; i <= n; ++i) {
//         b[i] = x - a[i];
//     }

//     build(1, 1, n);
//     int sum = 0;
//     for(int i = 1; i <= n; ++i) {
//         int t = qry(1, 1, n, i, i);
//         if(t > 0) {
//             mdf(1, 1, n, i, min(n, i + c - 1), -t);
//             sum += t;
//         }
//         if(sum > k) {
//             return 0;
//         }
//     }
//     return 1;
// }

// O(n) 复杂度的 check 函数
// h 是二分查找正在检查的目标高度
bool check(long long h) {
    // diff 数组用于差分，diff[i] 表示在位置 i，高度增量发生了多少变化
    // C++ 中建议使用 vector，它更安全且会自动管理内存
    vector<long long> diff(n + 2, 0); 

    long long total_ops = 0;      // 总操作次数
    long long current_increase = 0; // 当前位置生效的总增量

    for (int i = 1; i <= n; ++i) {
        // 1. 更新当前位置的总增量
        current_increase += diff[i];

        // 2. 计算当前木板的实际高度
        long long current_height = a[i] + current_increase;

        // 3. 如果高度不足，则进行操作
        if (current_height < h) {
            long long needed = h - current_height;

            // 4. 累加操作次数
            total_ops += needed;

            // 5. 如果操作次数已经超过 k，说明 h 不可能达到，直接返回 false
            if (total_ops > k) {
                return false;
            }

            // 6. 更新当前增量，因为我们对当前木板立即进行了增高
            current_increase += needed;

            // 7. 更新差分数组：在 i+c 的位置，本次操作失效，所以增量要减掉
            if (i + c <= n) {
                diff[i + c] -= needed;
            }
        }
    }

    // 8. 如果循环完成，说明 h 是可以达到的
    return true;
}

// main 函数中也要做相应修改
signed main() {
    n = read();
    k = read();
    c = read();

    for (int i = 1; i <= n; ++i) {
        a[i] = read();
    }

    long long l = 1, r = 2e9 + k; // 右边界可以设置得大一些，比如最高木板高度+k
    long long ans = 0;

    while (l <= r) {
        long long midd = l + (r - l) / 2; // 使用这种方式防止溢出
        if (check(midd)) {
            ans = midd;
            l = midd + 1;
        } else {
            r = midd - 1;
        }
    }
    
    writeln(ans);

    return 0;
}


// signed main() {

//     n = read();
//     k = read();
//     c = read();

//     for(int i = 1; i <= n; ++i) {
//         a[i] = read();
//     }

//     int l = 0, r = 1000000000;
//     int ans = 0;
//     while(l <= r) {
//         int midd = (l + r) >> 1;
//         if(check(midd)) {
//             ans = midd;
//             l = midd + 1;
//         }
//         else {
//             r = midd - 1;
//         }
//     }

//     // writeln(check(2));
//     // writeln()

//     writeln(ans);

//     return 0;
// }