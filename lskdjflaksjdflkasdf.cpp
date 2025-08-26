#include<bits/stdc++.h>
using namespace std;
using ll=long long;
#define IOS ios::sync_with_stdio(0);cin.tie(0)
#define fr(i,l,r) for(int i=(l);i<=(r);++i)
int main(){
    IOS;
    int T; if(!(cin>>T)) return 0;
    while(T--){
        int n; cin>>n;
        vector<ll>a(n+2,0);
        fr(i,1,n) cin>>a[i];
        ll ops=0;
        vector<ll> p(n+2,0);
        ll mx = LLONG_MIN/4;
        fr(i,1,n){
            if(i>=2) mx = max(mx, p[i-2]);
            int s = (i%2==0)?1:-1;
            p[i] = p[i-1] + s * a[i];
            if(p[i] < mx){
                ll need = mx - p[i];
                if(i%2==1){
                    ll dec = min(need, a[i]);
                    a[i] -= dec;
                    ops += dec;
                    p[i] += dec;
                } else {
                    ll dec = min(need, a[i-1]);
                    a[i-1] -= dec;
                    ops += dec;
                    p[i-1] += dec;
                    p[i] += dec;
                }
            }
        }
        cout<<ops<<"\n";
    }
    return 0;
}