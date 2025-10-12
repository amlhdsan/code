#include<bits/stdc++.h>
using namespace std;
int zzxc(int x,int y){
	if(x==0)return y;
	else return zzxc(y%x,x);
}

inline void q(int x, int y) {

}

inline void build(int p, int l, int r) {
    if(l == r) {
        tree[p] = a[l];
        return;
    }
    build(ls, l, mid);
    build(rs, mid + 1, r);
    tree[p] = tree[ls] + tree[rs];
}
int main(){
	int n,m;
	cin>>n>>m;
	int a,top,toq,xa,xb,ya,yb,za,zb,ans=0;
	a=zzxc(n,m);  //求最大公因数。
	char ch[500005],sh[500005];
	cin>>ch>>sh;
	for(int i=1;i<=a;i++){   //一组一组统计答案。
		xa=xb=ya=yb=za=zb=0;
		for(int j=i-1;j<n;j+=a){
			if(ch[j]=='R')xa++;
			if(ch[j]=='P')ya++;
			if(ch[j]=='S')za++;
		}
		for(int j=i-1;j<m;j+=a){
			if(sh[j]=='R')xb++;
			if(sh[j]=='P')yb++;
			if(sh[j]=='S')zb++;
		}
        ans+=min(min(min(xa+ya+zb,xa+yb+zb),xa+yb+za),min(min(xb+ya+zb,xb+ya+za),xb+yb+za));   //一共有六种可能，进行选择，找出不会出现平局的最少修改次数。
	}
	cout<<ans<<endl;
	return 0;
}
