#include <bits/stdc++.h>
using namespace std;

typedef long long int;
typedef vector<int> vint;

int read() {
	int a = 0, b = 0; char c = getchar();
	while (c < '0' || c > '9') b ^= (c == '-'), c = getchar();
	while (c >= '0' && c <= '9') a = a * 10 - 48 + c, c = getchar();
	return b ? -a : a;
}

const int N = 200005;
int n, k, c[N], l[N];
int su[N];

vint e1;
vint cl[N];
vint pa[N];
int p3[N];
vint ans;

int main() {
	// freopen("people.in", "r", stdin);
	// freopen("people.out", "w", stdout);
	n = read(), k = read();
	
	for (int i = 0; i < n; ++i) {
		c[i] = read(), l[i] = read();
		su[c[i]]++;
		su[(c[i] + l[i]) % k]--;
		su[0] += (c[i] + l[i]) / k;
		cl[c[i]].push_back(i);
	}
	for (int i = 1; i < k; ++i) su[i] += su[i - 1];
	int mn = *min_element(su, su + k);
	int st = 0, slen = 0;
	for (int i = 0; i < k; ++i) if (su[i] == mn) {
		int j = (i + 1) % k, le = 0;
		while (su[j] != mn) j = (j + 1) % k, ++le;
		if (le > slen) st = (i + 1) % k, slen = le;
	}
	for (int i = 0; i < k; ++i) su[i] -= mn;
	for (int i = 0; i < slen; ++i) su[(st + i) % k] --;
	
	if (slen) {
		vint df(k);
		for (int i = 0; i < k; ++i) if (su[i] == 0 && su[(i + 1) % k] != 0) {
			int j = (i + 1) % k;
			int p = j % k, curle = 0;
			while (su[p] != 0) p = (p + 1) % k, ++curle;
			//cerr << i << ' ' << j << ' ' << p << " ??\n";
			int cur = 0;
			while (j != p) {
				cur += df[j];
				su[j] += cur;
				while (su[j] != 0) {
					assert(cl[j].size() != 0);
					int ii = cl[j].back(); cl[j].pop_back();
					int le = min(l[ii], curle);
					//cerr << "del " << ii << ' ' << le << ' ' << l[ii] << ' ' << c[ii] << '\n';
					c[ii] = (c[ii] + le) % k;
					l[ii] -= le;
					assert(pa[ii].size() == 0);
					pa[ii].push_back(le);
					cl[c[ii]].push_back(ii);
					su[j]--; cur--;
					df[c[ii]]++;
				}
				j = (j + 1) % k;
				curle--;
			}
			// [j, p]
			if (p <= i) break;
			i = p;
		}
	}
	for (int i = 0; i < n; ++i) e1.push_back(i);
	int e = (st + slen) % k;
	cout << st << ' ' << mn * k + slen << '\n';
	//cerr << e << '\n';
	while (1) {
		if (cl[st].size()) {
			int ii = cl[st].back(); cl[st].pop_back();
			if (!l[ii]) continue;
			pa[ii].push_back(l[ii]);
			ans.push_back(l[ii]);
			st = (st + l[ii]) % k;
			//cerr << "? " << st << ' ' << c[ii] << ' ' << l[ii] << ' ' << ii << '\n';
			c[ii] = (c[ii] + l[ii]) % k;
			l[ii] = 0;
		} else if (st == (e) % k) {
			int fg = 0;
			while (1) {
				if (e1.size() == 0) {
					fg = 1;
					break;
				}
				int ii = e1.back(); e1.pop_back();
				int le;
				if (c[ii] < st) le = st - c[ii];
				else le = k - c[ii] + st;
				if (le < l[ii]) {
				//cerr << ii << ' ' << c[ii] << ' ' << l[ii] << ' ' << le << '\n';
					ans.push_back(l[ii] - le);
					st = (st + l[ii] - le + k) % k;
					p3[ii] = l[ii] - le;
					l[ii] = le;
					break;
				}
			}
			if (fg) break;
		} else assert(0);
	}
	for (int i = 0; i < n; ++i) if (p3[i]) pa[i].push_back(p3[i]);
	
	for (int i = 0; i < n; ++i) {
		cout << pa[i].size() << ' ';
		for (int j : pa[i]) cout << j << ' '; cout << '\n';
	}
	cout << ans.size() << ' ';
	for (int i : ans) cout << i << ' '; cout << '\n';
	
	
	
	
	
	return 0;
}