#include <bits/stdc++.h>

using namespace std;

int n;
int a[200];

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

inline void writeChar(char c) { putchar(c); }
inline void writeStr(const string &s) { for (char c : s) putchar(c); }

struct BigInt {
    static const int BASE = 10000;
    static const int WIDTH = 4;
    vector<int> d;

    BigInt(int x = 0) { *this = x; }

    BigInt& operator=(int x) {
        d.clear();
        if (x == 0) d.push_back(0);
        while (x > 0) {
            d.push_back(x % BASE);
            x /= BASE;
        }
        return *this;
    }

    void normalize() {
        while (d.size() > 1 && d.back() == 0) d.pop_back();
    }

    void mul(int m) {
        if (m == 0) { d.assign(1,0); return; }
        long long carry = 0;
        for (size_t i = 0; i < d.size(); ++i) {
            long long cur = 1LL * d[i] * m + carry;
            d[i] = int(cur % BASE);
            carry = cur / BASE;
        }
        while (carry) {
            d.push_back(int(carry % BASE));
            carry /= BASE;
        }
    }

    void div(int v) {
        long long carry = 0;
        for (int i = (int)d.size() - 1; i >= 0; --i) {
            long long cur = d[i] + carry * BASE;
            d[i] = int(cur / v);
            carry = cur % v;
        }
        normalize();
    }

    string toString() const {
        stringstream ss;
        int n = d.size();
        if (n == 0) return "0";
        ss << d.back();
        for (int i = n - 2; i >= 0; --i) {
            ss << setw(WIDTH) << setfill('0') << d[i];
        }
        return ss.str();
    }
};

int main() {

    n = read();

    int sum = 0;
    for(int i = 1; i <= n; ++i) 
        a[i] = read(), sum += a[i];

    if(sum != 2 * (n - 1)) {
        writeChar('0');
        writeChar('\n');
        return 0;
    }

    if(n == 1) {
        if(a[1] == 0) {
            writeChar('1');
            writeChar('\n');
            return 0;
        }
        else {
            writeChar('0');
            writeChar('\n');
            return 0;
        }
    }

    if(n == 2) {
        if(a[1] == 1 && a[2] == 1) {
            writeChar('1');
            writeChar('\n');
            return 0;
        }
        else {
            writeChar('0');
            writeChar('\n');
            return 0;
        }
    }

    BigInt ans(1);

    for (int k = 2; k <= max(0, n - 2); ++k) {
        ans.mul(k);
    }

    for (int i = 1; i <= n; ++i) {
        for (int j = 2; j <= a[i] - 1; ++j) {
            ans.div(j);
        }
    }

    writeStr(ans.toString());
    writeChar('\n');

    return 0;
}