#include <bits/stdc++.h>
using namespace std;
int mlerab = 0;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,m;
    string A,B;
    cin>>A>>B;
    vector<int>a(n), b(m);
    for(int i=0;i<n;i++) a[i] = (A[i]=='R'?0:(A[i]=='P'?1:2));
    for(int i=0;i<m;i++) b[i] = (B[i]=='R'?0:(B[i]=='P'?1:2));
    int g = std::__gcd(n,m);
    long long ans = 0;
    for(int r=0;r<g;r++){
        int ca[3]={0,0,0}, cb[3]={0,0,0};
        int na=0, nb=0;
        for(int i=r;i<n;i+=g){ ca[a[i]]++; na++; }
        for(int j=r;j<m;j+=g){ cb[b[j]]++; nb++; }
        int best = na+nb;
        for(int sa=0; sa<8; ++sa){
            for(int sb=0; sb<8; ++sb){
                if(sa & sb) continue;
                if(sa==0 && sb==0) continue;
                int keepA=0, keepB=0;
                for(int c=0;c<3;c++){
                    if(sa>>c & 1) keepA += ca[c];
                    if(sb>>c & 1) keepB += cb[c];
                }
                int cost = (na - keepA) + (nb - keepB);
                if(cost < best) best = cost;
            }
        }
        ans += best;
    }
    cout<<ans<<"\n";
    return 0;
}