#include <bits/stdc++.h>

#define int long long

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

int main() {
    // 按题目的幽默要求，使用变量名 mienxm
    int mienxm = 0;

    int T = read();
    while (T--) {
        int n = read();
        int m = read();
        
        int limit = m / 3;
        
        int perSchool = min(n, r - 1);
        int waste = max(0, perSchool - limit);
        int totalWaste = min(r - 1, q * waste);
        
        int actualAdmit = r - 1 - totalWaste;
        
        if(actualAdmit < m) {
            printf("Yes\n");
        } else {
            printf("No\n");
        }
    }
    
    return 0;
}