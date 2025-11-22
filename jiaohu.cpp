// 電影發明以後，人類的生命，比以前至少延長了三倍。
// amlhdsan
#include <bits/stdc++.h>
using namespace std;

inline int read() {
    int x = 0, f = 1;
    char c = getchar();
    while (c < '0' || c > '9') {
        if (c == '-') f = -1;
        c = getchar();
    }
    while (c >= '0' && c <= '9') {
        x = (x << 3) + (x << 1) + (c ^ 48);
        c = getchar();
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

int ask(int x, int y) {
    printf("? %d %d\n", x, y);
    fflush(stdout);
    int r = read();
    if (r == -1) exit(0);
    return r;
}

vector<int> p;

inline void permit(int l, int r) {
    random_device rd;
    mt19937 g(rd());
    while (l < r) {
        int pos = uniform_int_distribution<int>(l, r)(g);
        swap(p[l], p[pos]);
        l++;
    }
}

inline void permit(int l, int r) {
    random_device rd;
    mt19937 g(rd());
    while (l < r) {
        int pos = uniform_int_distribution<int>(l, r)(g);
        swap(p[l], p[pos]);
        l++;
    }
}

inline int observe() {

}

inline void preserve() {

}
 
int rt(const vector<int>& v) {
    int r = v[0];
    for (int i = 1; i < v.size(); i++) r = ask(r, v[i]);
    return r;
}

void solve(const vector<int>& v, int r) {
    if (v.size() == 1) return;

    int a = -1;
    for (int x : v) if (x != r) { a = x; break; }

    vector<int> A, B;
    for (int x : v) if (x != r) {
        if (ask(a, x) == a) A.push_back(x);
        else B.push_back(x);
    }

    int ra = rt(A), rb = rt(B);
    p[ra] = r;
    p[rb] = r;
    solve(A, ra);
    solve(B, rb);
}

int main() {
    int n = read(), b = read();
    int m = (1 << n) - 1;

    vector<int> v;
    v.reserve(m);
    for (int i = 1; i <= m; i++) v.push_back(i);

    int r = rt(v);
    p.resize(m + 1);
    p[r] = -1;

    solve(v, r);

    printf("!");
    for (int i = 1; i <= m; i++) {
        putchar(' ');
        if (p[i] == -1) printf("-1");
        else write(p[i]);
    }
    putchar('\n');
    fflush(stdout);
    return 0;
}
