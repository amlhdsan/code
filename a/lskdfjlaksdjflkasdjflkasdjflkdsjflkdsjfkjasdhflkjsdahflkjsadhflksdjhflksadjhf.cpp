#include <bits/stdc++.h>

#define N 200001

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

int n;
int a[N];
map<int, vector<int>> pos;
int dp[N];

void solve() {
   n = read();
   pos.clear();
   
   for (int i = 1; i <= n; ++i) {
       a[i] = read();
   }
   
   for (int i = 0; i <= n; ++i) {
       dp[i] = 0;
   }
   
   for (int i = 1; i <= n; ++i) {
       int v = a[i];
       pos[v].push_back(i);
       
       dp[i] = dp[i - 1];
       
       int k = pos[v].size();
       if (k >= v) {
           int st = pos[v][k - v];
           dp[i] = max(dp[i], dp[st - 1] + v);
       }
   }
   
   writeln(dp[n]);
}

int main() {
   int t = read();
   while (t--) {
       solve();
   }
   return 0;
}