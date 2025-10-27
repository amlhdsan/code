      
#include <bits/stdc++.h>
using namespace std;
const int maxn = 100010;
int n, k, a[maxn], cnt[maxn], ql = 1, qr;
long long f[21][maxn], now;
inline long long func(int l, int r) {
  while(ql > l) now += cnt[a[--ql]]++;
  while(qr < r) now += cnt[a[++qr]]++;
  while(ql < l) now -= --cnt[a[ql++]];
  while(qr > r) now -= --cnt[a[qr--]];
  return now;
}
inline void calc(int k, int dl, int dr, int l, int r) {
  if(l > r) return;
  int md = (l + r) / 2, pos = 0;
  for(int i = dl; i <= min(md - 1, dr); ++i) {
    long long w = func(i + 1, md);
    if(f[k - 1][i] + w < f[k][md]) f[k][md] = f[k - 1][i] + w, pos = i;
  }
  calc(k, dl, pos, l, md - 1), calc(k, pos, dr, md + 1, r);
}
inline void solve() {
  cin >> n >> k;
  for(int i = 1; i <= n; ++i) cin >> a[i];
  memset(f, 0x3f, sizeof f), f[0][0] = 0;
  for(int i = 1; i <= k; ++i) calc(i, 0, n - 1, 1, n);
  cout << f[k][n] << '\n';
}
int main() {
	freopen("divide.in", "r", stdin);
	freopen("divide.out", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  solve();
  return 0;
}

    