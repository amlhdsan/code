#include <bits/stdc++.h>

#define N 1000010

using namespace std;

int n;
int h[N], v[N];
int lf[N], rf[N];
int ans[N];
stack<pair<int, int> > q1, q2;

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

    freopen("1.in", "r", stdin);
    freopen("station.out", "w", stdout);

    n = read();

    for(int i = 1; i <= n; ++i) {
        h[i] = read();
        v[i] = read();
    }
    h[0] = 0x7fffffff;
    h[n + 1] = 0x7fffffff;

    for(int i = 1; i <= n; ++i) {
        if(q1.empty()) {
            q1.push(make_pair(h[i], i));
        }
        else if(h[i] < q1.top().first) {
            q1.push(make_pair(h[i], i));
        }
        else {
            while(!q1.empty()) {
                if(h[i] > q1.top().first) {
                    rf[q1.top().second] = i;
                    q1.pop();
                }
                else {
                    q1.push(make_pair(h[i], i));
                    break;
                }
            }
            if(q1.empty()) {
                q1.push(make_pair(h[i], i));
            }
        }
    }

    for(int i = n; i >= 1; --i) {
        if(q2.empty()) {
            q2.push(make_pair(h[i], i));
        }
        else if(h[i] < q2.top().first) {
            q2.push(make_pair(h[i], i));
        }
        else {
            while(!q2.empty()) {
                if(h[i] > q2.top().first) {
                    lf[q2.top().second] = i;
                    q2.pop();
                }
                else {
                    q2.push(make_pair(h[i], i));
                    break;
                }
            }
            if(q2.empty()) {
                q2.push(make_pair(h[i], i));
            }
        }
    }

    for(int i = 1; i <= n; ++i) {
        // write(lf[i]), putchar(' '), writeln(rf[i]);
        ans[lf[i]] += v[i];
        ans[rf[i]] += v[i];
    }

    int maxx = -1;

    for(int i = 1; i <= n; ++i) {
        maxx = max(maxx, ans[i]);
    }

    writeln(maxx);

    return 0;
}