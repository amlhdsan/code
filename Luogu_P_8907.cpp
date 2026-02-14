/*
const int N=2e5+7;
int n,m;
set<int>g[N];

void Main(){
	n=read();m=read();
	for(int i=1;i<=m;i++){
		int u=read(),v=read();
		g[min(u,v)].insert(max(u,v));
	}
	ll ans=-m;
	for(int i=1;i<=n;i++){
		if(g[i].empty())continue;
		ans+=g[i].size();
		int u=*g[i].begin(),v=i;g[v].erase(g[v].begin());
		if(g[u].size()<g[v].size())swap(g[u],g[v]);
		for(auto i:g[v])g[u].insert(i);
	}
	cout<<ans;
	return;
}
*/
#include <bits/stdc++.h>

#define N 200010

using namespace std;

int n, m;

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

int main() {
    
    n = read();
    m = read();

    for(int i = 1; i <= m; ++i) {
        int u = read(), v = read();
    }

    

    return 0;
}