#include <bits/stdc++.h>

#define N 100005
#define ll long long

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

int n, k;
int a[N];
bool vis[N];
vector<int> primes;

void sieve() {
    for (int i = 2; i < N; i++) {
        if (!vis[i]) {
            primes.push_back(i);
            for (ll j = 1ll * i * i; j < N; j += i) {
                vis[j] = true;
            }
        }
    }
}

int main() {
    sieve();
    
    n = read();
    k = read();
    
    for (int i = 1; i <= n; i++) {
        a[i] = read();
    }
    
    for (int p : primes) {
        ll ops = 0;
        bool ok = true;
        
        for (int i = 1; i <= n; i++) {
            int rem = a[i] % p;
            if (rem != 0) {
                int need = p - rem;
                ops += (need + k - 1) / k;
                if (ops > k) {
                    ok = false;
                    break;
                }
            }
        }
        
        if (ok) {
            for (int i = 1; i <= n; i++) {
                int rem = a[i] % p;
                if (rem != 0) {
                    int need = p - rem;
                    int cnt = (need + k - 1) / k;
                    a[i] += cnt * k;
                }
            }
            break;
        }
    }
    
    for (int i = 1; i <= n; i++) {
        write(a[i]);
        if (i < n) putchar(' ');
    }
    putchar('\n');
    
    return 0;
}