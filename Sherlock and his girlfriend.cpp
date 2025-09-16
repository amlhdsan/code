#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    if(!(cin>>n)) return 0;
    if(n<=2){
        cout<<1<<"\n";
        for(int i=0;i<n;i++){
            if(i) cout<<" ";
            cout<<1;
        }
        cout<<"\n";
        return 0;
    }
    int m = n+2;
    vector<char> is_prime(m+1,1);
    is_prime[0]=is_prime[1]=0;
    for(int i=2;i*i<=m;i++) if(is_prime[i]) for(int j=i*i;j<=m;j+=i) is_prime[j]=0;
    cout<<2<<"\n";
    for(int x=2;x<=n+1;x++){
        if(x>2) cout<<" ";
        cout<<(is_prime[x]?1:2);
    }
    cout<<"\n";
    return 0;
}