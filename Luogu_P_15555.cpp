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
    write(x);
    putchar('\n');
}

inline void solve() {
    double xb, yb, vx,vy;
    double y1, y2, vy1, vy2;
    double x1, x2,vx1, vx2;
    cin >> xb >> yb>> vx >> vy;
    cin >> y1 >> y2 >> vy1 >> vy2;
    cin >> x1 >> x2 >> vx1 >> vx2;

    double tm = (double)(y2 - y1) / (vy1+vy2);
    double y = y1 + vy1 * tm;
    
    double nwt = 0;
    double nwx = xb;
    double nwv = vx;

    while(nwt < tm) {
        double dt = -1.0;
        if(nwv > vx2) {
            dt = (x2 - nwx+vx2 * nwt) / (nwv - vx2);
        }
        else if(nwv < -vx1){dt = (x1 - nwx - vx1*nwt)/(nwv + vx1);}
        if(dt < 0  || nwt + dt >= tm) {

        }
    }
}

int main() {

    int t = read();
    while(t--) {
        solve();
    }

    return 0;
}