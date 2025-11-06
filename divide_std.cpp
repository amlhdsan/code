      
#include <bits/stdc++.h>
using namespace std;

// Divide & Conquer DP + sliding window cost (经典分割序列使重复对数和最小化)
const int maxn = 100010;
int n, k;
int a[maxn];           // 1-indexed 输入序列
int cnt[maxn];         // 统计当前窗口内每个值的频次
int ql, qr;            // 当前窗口左右端点，表示 [ql, qr]
long long now;         // 当前窗口的丑陋值（相同数对的数量）
long long f[21][maxn]; // DP 表 f[t][i]

// 将当前滑动窗口移动到 [l, r] 并返回该区间的 cost（丑陋值）
inline long long func(int l, int r) {
  while (ql > l) now += cnt[a[--ql]]++;
  while (qr < r) now += cnt[a[++qr]]++;
  while (ql < l) now -= --cnt[a[ql++]];
  while (qr > r) now -= --cnt[a[qr--]];
  return now;
}

// 分治优化计算 f[t][i] 在 i∈[l, r] 的值，已知 opt 位于 [dl, dr]
inline void calc(int t, int dl, int dr, int l, int r) {
  if (l > r) return;
  int md = (l + r) >> 1;
  int opt = dl;
  long long best = LLONG_MAX / 4;

  // 枚举可能的分割点 j ∈ [dl, min(md-1, dr)]
  int ub = min(md - 1, dr);
  for (int j = dl; j <= ub; ++j) {
    long long w = func(j + 1, md);
    long long val = f[t - 1][j] + w;
    if (val < best) {
      best = val;
      opt = j;
    }
  }

  f[t][md] = best;
  // 递归处理左右区间，传递 opt 边界
  calc(t, dl, opt, l, md - 1);
  calc(t, opt, dr, md + 1, r);
}

inline void solve() {
  cin >> n >> k;
  for (int i = 1; i <= n; ++i) cin >> a[i];

  // 初始化 DP 为一个足够大的值
  const long long INF = LLONG_MAX / 4;
  for (int t = 0; t <= k; ++t) for (int i = 0; i <= n; ++i) f[t][i] = INF;
  f[0][0] = 0;

  // 对每一层 t，使用分治优化计算 f[t][1..n]
  for (int t = 1; t <= k; ++t) {
    // 在每一层开始前重置滑动窗口状态与计数器
    ql = 1; qr = 0; now = 0;
    // cnt 的索引范围应覆盖 a[i] 的取值，这里清零前 maxn 个槽
    memset(cnt, 0, sizeof(cnt));
    calc(t, 0, n - 1, 1, n);
  }

  cout << f[k][n] << '\n';
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  // 如果需要文件输入/输出，可解除下面两行注释并调整文件名
  // freopen("divide.in", "r", stdin);
  // freopen("divide.out", "w", stdout);

  solve();
  return 0;
}

    