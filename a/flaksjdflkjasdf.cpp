#include <bits/stdc++.h>

#define N 200010

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
char s[N];
int p[N];
int zero[N], one[N];

void solve() {
   n = read(); k = read();
   scanf("%s", s);
   
   int cnt = 0;
   bool flag = 0;
   
   for (int i = 0; i < k; ++i) {
       if (s[i] == '1') cnt++;
   }
   
   if (cnt == k) flag = 1;
   
   for (int i = k; i < n && !flag; ++i) {
       if (s[i] == '1') cnt++;
       if (s[i - k] == '1') cnt--;
       if (cnt == k) flag = 1;
   }
   
   if (flag) {
       puts("NO");
       return;
   }
   
   puts("YES");
   
   int z = 0, o = 0;
   for (int i = 0; i < n; ++i) {
       if (s[i] == '0') zero[z++] = i;
       else one[o++] = i;
   }
   
   int val = 1;
   for (int i = 0; i < o; ++i) {
       p[one[i]] = val++;
   }
   
   val = n;
   for (int i = 0; i < z; ++i) {
       p[zero[i]] = val--;
   }
   
   for (int i = 0; i < n; ++i) {
       write(p[i]);
       if (i < n - 1) putchar(' ');
   }
   putchar('\n');
}

int main() {
   int t = read();
   while (t--) {
       solve();
   }
   return 0;
}