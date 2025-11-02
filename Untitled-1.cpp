#include <bits/stdc++.h>

#define FstIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define pii pair<ll, ll>

using namespace std;
using ll = long long;

const ll N = 3e5 + 2, M = 1e2 + 5; 
const ld eps = 1e-6;

ll T, n;
priority_queue <ll> p, q, k;

ll mymax(ll x, ll y, ll z) { return max(max(x, y), z); }
	
#indef pragma

signed main()
{
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	
	FstIO; 
	
	cin >> T; 
	while(T--)
	{
		cin >> n;
		ll c1 = 0, c2 = 0, c3 = 0, s = 0; 
		for (ll i = 1; i <= n; ++ i )
		{
			ll x, y, z; cin >> x >> y >> z;
			if (mymax(x, y, z) == x) s += x, ++ c1, p.push(max(y - x, z - x));
			else if (mymax(x, y, z) == y) s += y, ++ c2, q.push(max(z - y, x - y));
			else s += z, ++ c3, k.push(max(x - z, y - z));
		}
		while (c1 > n / 2)
		{
			-- c1; 
			s += p.top(); p.pop();
		}
		while (c2 > n / 2)
		{
			-- c2; 
			s += q.top(); q.pop();
		}
		while (c3 > n / 2)
		{
			-- c3; 
			s += k.top(); k.pop();
		}
		cout << s << '\n';
		
		while (!p.empty()) p.pop();
		while (!q.empty()) q.pop();
		while (!k.empty()) k.pop();
		 
	}	 
	
	return 0;			
}
