#include <bits/stdc++.h>

#define N 100001

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

int t, n;
int a[N];
int jmp[N];

void swp(int x) {
   printf("swap %d\n", x + 1);
   fflush(stdout);
}

int thrw(int x) {
   printf("throw %d\n", x + 1);
   fflush(stdout);
   int ret = read();
   return ret;
}

void ans() {
   putchar('!');
   for(int i = 0; i < n; ++i) {
       putchar(' ');
       write(a[i]);
   }
   putchar('\n');
   fflush(stdout);
}

int main() {
   t = read();
   while(t--) {
       n = read();
       
       for(int i = n - 1; i >= 0; --i) {
           if(jmp[i + 1] == jmp[i + 2]) {
               jmp[i] = jmp[i + 1] + 1;
           } else {
               jmp[i] = thrw(i);
               if(jmp[i] == jmp[i + 1] + 1)
                   a[i] = 1;
               else
                   a[i] = 2;
           }
       }
       
       for(int i = 0; i + 1 < n; ++i) {
           if(a[i] == 0) {
               swp(i);
               int ji = thrw(i + 1);
               if(ji == jmp[i + 2] + 1)
                   a[i] = 1;
               else
                   a[i] = 2;
           }
       }
       
       swp(n - 2);
       int jlast = thrw(n - 2);
       if(jlast == 2)
           a[n - 1] = 1;
       else
           a[n - 1] = 2;
           
       ans();
   }
   
   return 0;
}