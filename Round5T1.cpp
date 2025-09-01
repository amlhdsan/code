#include <bits/stdc++.h>

#define N 100010
#define INF 1000000000000000000
#define int long long

using namespace std;

inline int read() {
    int w = 0, f = 1;
    char ch = getchar();
    while(ch < '0' || ch > '9') {
        if(ch == '-') {
            f = -1;
        }
        ch = getchar();
    }
    while(ch >= '0' && ch <= '9') {
        w = (w << 3) + (w << 1) + (ch - '0');
        ch = getchar();
    }
    return w * f;
}

inline void write(int x) {
    if(x < 0) {
        putchar('-');
        x = -x;
    }
    if(x >= 10) write(x / 10);
    putchar(x % 10 + '0');
}

int n, res, a[N], suf[N], h[N], cur, sum;

void sol() {
	n = read();
    cur = n;
    res = sum = 0;
    a[0] = INF;
	for(int i = 1; i <= n; ++i) {
		a[i] = read();
        sum += a[i];
		a[i] = min(a[i - 1], a[i]);
        h[i] = 0;
	}
	for(int i = 1; i <= n; ++i) {
		while(cur && a[cur] < i) 
            cur--;      
		if(!cur) 
            break;
		h[i] = min(a[i], cur);
        a[i] = min(a[i], cur);
		while(cur > h[i]) {
            a[cur]=min(a[cur], i - 1);
            cur--;
        }
	}
	for(int i = 1; i <= n; ++i) 
        res += h[i];
	write(sum - res);
    putchar('\n');
}
int main()
{
	freopen("cube.in", "r", stdin);
	freopen("cube.out", "w", stdout);
	int T = read();
	while(T--) 
        sol();
	return 0;
}