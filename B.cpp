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
    if (x < 0) {
        putchar('-');
        x = -x;
    }
    if (x > 9) writeln(x / 10);
    putchar(x % 10 + '0');
    putchar('\n');
}

const int MAXN = 200005;
int arr[MAXN];
long long vals[MAXN];
long long freq[MAXN];

void printll(long long x) {
    if (x < 0) {
        putchar('-');
        x = -x;
    }
    if (x > 9) printll(x / 10);
    putchar(x % 10 + '0');
}

int main() {
    int t = read();
    while (t--) {
        int n = read();
        for (int i = 0; i < n; ++i) arr[i] = read();
        sort(arr, arr + n);
        int m = 0;
        for (int i = 0; i < n; ) {
            int j = i;
            while (j < n && arr[j] == arr[i]) ++j;
            vals[m] = arr[i];
            freq[m] = j - i;
            ++m;
            i = j;
        }
        long long alice = 0, bob = 0;
        int turn = 0;
        for (int i = 0; i < m; ++i) {
            long long len = vals[i];
            long long takeA = 0, takeB = 0;
            if (turn == 0) {
                takeA = (len + 1) / 2;
                takeB = len / 2;
            } else {
                takeB = (len + 1) / 2;
                takeA = len / 2;
            }
            alice += takeA * freq[i];
            bob += takeB * freq[i];
            if (len % 2 == 1) turn ^= 1;
        }
        printll(alice);
        putchar(' ');
        printll(bob);
        putchar('\n');
    }
    return 0;
}
