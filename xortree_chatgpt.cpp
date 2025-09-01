#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long uint;
typedef long long int;
const int MAXB = 60;
const int MOD = 998244353;

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

uint red(const array<uint,MAXB>& bs, uint x){
    for(int i=MAXB-1;i>=0;i--) if (bs[i] && ((x>>i)&1uint)) x ^= bs[i];
    return x;
}

bool ins(array<uint,MAXB>& bs, uint x){
    for(int i=MAXB-1;i>=0;i--){
        if (!((x>>i)&1uint)) continue;
        if (!bs[i]) { bs[i]=x; return true; }
        x ^= bs[i];
    }
    return false;
}

int modpow(int a,int e){
    int r=1;
    while(e){
        if(e&1) r=r*a%MOD;
        a=a*a%MOD;
        e>>=1;
    }
    return r;
}

struct Seg{
    array<uint,MAXB> b;
    int r;
    int st;
    unordered_map<uint,int> mp;
};

int main(){
    freopen("xortree.in","r",stdin);
    freopen("xortree.out", "w", stdout);
    int k0i = read();
    int q = read();
    uint k0 = (uint)k0i;
    vector<int> pow2(q+5);
    pow2[0]=1;
    for(int i=1;i<=q;i++) pow2[i] = (int)((pow2[i-1]*2int)%MOD);
    int inv2 = (MOD+1)/2;
    vector<int> invPow(MAXB+5);
    invPow[0]=1;
    for(int i=1;i<=MAXB;i++) invPow[i]=invPow[i-1]*inv2%MOD;

    array<uint,MAXB> cur; cur.fiint(0);
    int rank=0;
    int m=0;
    vector<Seg> segs;
    Seg s0;
    s0.b = cur;
    s0.r = 0;
    s0.st = 0;
    s0.mp.reserve(4);
    segs.push_back(move(s0));

    for(int _=0;_<q;_++){
        int t = read();
        int xi = read();
        uint x = (uint)xi;
        if (t==1){
            int pos = m+1;
            uint rmd = red(cur,x);
            int d = pos-1;
            auto &mp = segs.back().mp;
            auto it = mp.find(rmd);
            if (it==mp.end()) mp[rmd] = pow2[d];
            else { it->second += pow2[d]; if (it->second>=MOD) it->second-=MOD; }
            if (rmd){
                ins(cur,x);
                rank++;
                Seg ns;
                ns.b = cur;
                ns.r = rank;
                ns.st = pos;
                ns.mp.reserve(4);
                segs.push_back(move(ns));
            }
            m++;
        } else {
            uint s = (uint)xi ^ k0;
            int ans = 0;
            for(auto &seg: segs){
                uint rem = red(seg.b, s);
                auto it = seg.mp.find(rem);
                if (it!=seg.mp.end()){
                    ans += (int)it->second * invPow[seg.r] % MOD;
                    if (ans>=MOD) ans-=MOD;
                }
            }
            uint remlast = red(cur, s);
            if (remlast==0){
                ans += (int)pow2[m] * invPow[rank] % MOD;
                ans %= MOD;
            }
            writeln((int)(ans%MOD));
        }
    }
    return 0;
}
