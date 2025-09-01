#include <bits/stdc++.h>
using namespace std;
typedef long long int;
inline int read(){int x=0,f=1;char ch=getchar();while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}while(ch>='0'&&ch<='9'){x=(x<<3)+(x<<1)+(ch^48);ch=getchar();}return x*f;}
inline void write(int x){if(x<0){putchar('-');x=-x;} if(x>9) write(x/10); putchar(x%10+'0');}
inline void writeln(int x){write(x); putchar('\n');}
int main(){
    freopen("shopping.in","r",stdin);
    freopen("shopping.out","w",stdout);
    int n=read();
    int m;
    m = read();
    vector<int> P(n);
    for(int i=0;i<n;i++) P[i]=read();
    long double maxT=0;
    for(int i=0;i<n;i++){
        long double cand = 2.0L*sqrt((long double)m*(long double)P[i]) + P[i];
        if(cand>maxT) maxT=cand;
    }
    int R = (int)maxT + 1;
    int low=0, high=R, ansItems=0;
    while(low<=high){
        int mid = (low+high)>>1;
        __int128 totCost=0;
        int totItems=0;
        for(int i=0;i<n;i++){
            if(mid < P[i]) continue;
            int k = (mid + P[i])/(2*P[i]);
            totItems += k;
            totCost += ( (__int128)P[i]*k*k );
            if(totCost>m) break;
        }
        if(totCost<=m){ ansItems=totItems; low=mid+1; }
        else high=mid-1;
    }
    writeln((int)ansItems);
    return 0;
}
