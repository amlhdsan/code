#include <bits/stdc++.h>

#define int long long
#define N 5001000
#define SN 55000

using namespace std;

int n;
int a[N];
int sn;
int id[N];
int tag[SN];
vector<int> v[SN];

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
    int l = (p - 1LL) * sn + 1LL;
    int r = min(p * sn, n);

    v[p].clear();

    for(int i = l; i <= r; ++i) {
        v[p].push_back(a[i]);
    }

    sort(v[p].begin(), v[p].end());
}

inline void mdf(int l, int r, int x) {
    for(int i = l; i <= min(id[l] * sn, r); ++i) {
        a[i] += x;
    }

    upd(id[l]);

    if(id[l] != id[r]) {
        for(int i = (id[r] - 1LL) * sn + 1LL; i <= r; ++i) {
            a[i] += x;
        }
        upd(id[r]);
    }

    for(int i = id[l] + 1LL; i <= id[r] - 1LL; ++i) {
        tag[i] += x;
    }
}

inline void qry(int l, int r, int x) {
    int ans = 0;

    for(int i = l; i <= min(id[l] * sn, r); ++i) {
        if(a[i] + tag[id[l]] < x) {
            ++ans;
        }
    }

    if(id[l] != id[r]) {
        for(int i = (id[r] - 1LL) * sn + 1LL; i <= r; ++i) {
            if(a[i] + tag[id[r]] < x) {
                ++ans;
            }
        }
    }

    for(int i = id[l] + 1LL; i <= id[r] - 1LL; ++i) {
        ans += lower_bound(v[i].begin(), v[i].end(), x - tag[i]) - v[i].begin();
    }

    writeln(ans);

    return;
}

signed main() {

    n = read();
    sn = sqrt(n);

    for(int i = 1; i <= n; ++i) {
        a[i] = read();
    }
     
    for(int i = 1; i <= n; ++i) {
        id[i] = (i - 1) / sn + 1;
        v[id[i]].push_back(a[i]);
    }

    for(int i = 1; i <= id[n]; ++i) {
        sort(v[i].begin(), v[i].end());
    }

    for(int i = 1; i <= n; ++i) {
        int opt, l, r, c;

        opt = read();
        l = read();
        r = read();
        c = read();

        if(opt == 0) {
            mdf(l, r, c);
        }
        else {
            qry(l, r, c * c * 1LL);
        }
    }

    return 0;
}