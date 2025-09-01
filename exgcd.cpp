#include <bits/stdc++.h>

#define N 100001
#define int long long

using namespace std;

int n;
int a[N], b[N];

int gcd(int a, int b) {
	if(!b) 
        return a;
	else return gcd(b, a % b);
}

inline int read() {
    int x = 0, f = 1;
    char ch = getchar();
    while(ch < '0' || ch > '9') {
        if(ch == '-') {
            f = -1;
        }
        ch = getchar();
    }
    while(ch >= '0' && ch <= '9') {
        x = (x << 3) + (x << 1) + (ch ^ 48);
        ch = getchar();
    }
    return x * f;
}

void merge(int p1, int a1, int p2, int a2, int &p, int &a) {
	p = p1 / gcd(p1, p2) * p2;
	if(p1 < p2) {
        swap(p1, p2);
        swap(a1, a2);
    }
	a = a1;
	while(a % p2 != a2)
		a += p1;
}
int main() {

	n = read();

    for(int i = 1; i <= n; ++i) {
        a[i] = read();
        b[i] = read();
        b[i] %= a[i];
    }

    for(int i = 2; i <= n; ++i) {
        merge(a[i], b[i], a[i - 1], b[i - 1], a[i], b[i]);
    }

    cout << b[n] << endl;

	return 0;
}
