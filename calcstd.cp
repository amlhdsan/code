// 電影發明以後，人類的生命，比以前至少延長了三倍。
// amlhdsan
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

inline void write(long long x) {
    if (x < 0) {
        putchar('-');
        x = -x;
    }
    if (x > 9) write(x / 10);
    putchar(x % 10 + '0');
}

inline void writeln(long long x) {
    write(x);
    putchar('\n');
}

const int N = 500000 + 5;
int n, q;
int p[N];
long long le[N], ri[N];
char op[N];
long long a[N];
__int128 dlt[N];
__int128 Lfull[N], Rfull[N];

long long qs[1000005];
long long mnQ = 1e18, mxQ = -1e18;

long long c[3000005];
int tot;
long long seg[12000005];
long long lz[12000005];

void add(int id,long long v,int L,int R,int p,int q){
    if(L==p && R==q){
        lz[id]+=v;
        return;
    }
    int mid=(L+R)>>1;
    if(q<=mid) add(id<<1,v,L,mid,p,q);
    else if(p>mid) add(id<<1|1,v,mid+1,R,p,q);
    else{
        add(id<<1,v,L,mid,p,mid);
        add(id<<1|1,v,mid+1,R,mid+1,q);
    }
}

long long ask(int id,int L,int R,int p){
    long long r=lz[id];
    if(L==R) return r;
    int mid=(L+R)>>1;
    if(p<=mid) return r+ask(id<<1,L,mid,p);
    else return r+ask(id<<1|1,mid+1,R,p);
}

int idx(long long x){
    int l=1,r=tot,pos=tot;
    while(l<=r){
        int mid=(l+r)>>1;
        if(c[mid]>=x) pos=mid, r=mid-1;
        else l=mid+1;
    }
    return pos;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>n>>q;
    for(int i=2;i<=n;i++){
        cin>>p[i]>>le[i]>>ri[i];
    }
    for(int i=1;i<=n;i++){
        cin>>op[i]>>a[i];
    }
    for(int i=1;i<=q;i++){
        cin>>qs[i];
        if(qs[i]<mnQ) mnQ=qs[i];
        if(qs[i]>mxQ) mxQ=qs[i];
    }

    __int128 INF=(__int128)1<<120;
    Lfull[1]=-INF; Rfull[1]=INF;
    dlt[1]=(op[1]=='+'? (__int128)a[1]: -(__int128)a[1]);

    vector<long long> vt;
    vt.push_back(mnQ);
    vt.push_back(mxQ+1);

    for(int i=2;i<=n;i++){
        int fa=p[i];
        __int128 Ls=(__int128)le[i]-dlt[fa];
        __int128 Rs=(__int128)ri[i]-dlt[fa];
        __int128 nl=Lfull[fa]>Ls?Lfull[fa]:Ls;
        __int128 nr=Rfull[fa]<Rs?Rfull[fa]:Rs;
        Lfull[i]=nl; Rfull[i]=nr;
        dlt[i]=dlt[fa]+(op[i]=='+'? (__int128)a[i]: -(__int128)a[i]);

        if(nl<=nr){
            __int128 L2 = nl< (__int128)mnQ ? (__int128)mnQ : nl;
            __int128 R2 = nr> (__int128)mxQ ? (__int128)mxQ : nr;
            if(L2<=R2){
                vt.push_back((long long)L2);
                vt.push_back((long long)R2+1);
            }
        }
    }

    for(int i=1;i<=q;i++) vt.push_back(qs[i]);

    sort(vt.begin(), vt.end());
    vt.erase(unique(vt.begin(), vt.end()), vt.end());
    tot=vt.size();
    for(int i=1;i<=tot;i++) c[i]=vt[i-1];

    if(mnQ<=mxQ){
        int L=idx(mnQ);
        int R=idx(mxQ+1)-1;
        add(1,1,1,tot,L,R);
    }

    for(int i=2;i<=n;i++){
        if(Lfull[i]<=Rfull[i]){
            __int128 L2 = Lfull[i]< (__int128)mnQ ? (__int128)mnQ : Lfull[i];
            __int128 R2 = Rfull[i]> (__int128)mxQ ? (__int128)mxQ : Rfull[i];
            if(L2<=R2){
                int L=idx((long long)L2);
                int R=idx((long long)R2+1)-1;
                add(1,1,1,tot,L,R);
            }
        }
    }

    for(int i=1;i<=q;i++){
        int id=idx(qs[i]);
        long long ans=ask(1,1,tot,id);
        writeln(ans);
    }

    return 0;
}
