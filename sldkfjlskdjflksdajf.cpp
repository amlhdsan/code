#include<bits/stdc++.h>
#define int long long
using namespace std;
int max(int x,int y){return x>y? x:y;}
int min(int x,int y){return x<y? x:y;}
inline int read(){
	char c=getchar();
	int sum=0,flag=1;
	while(!isdigit(c)){if(c=='-')flag=-1;c=getchar();}
	while(isdigit(c)){sum=(sum<<1)+(sum<<3)+(c^48),c=getchar();}
	return sum*flag;
}
inline void write(int x){
	if(x<0) x=(~x)+1,putchar('-');
	if(x>9) write(x/10);
	putchar(x%10|48); 
}
const int N=1e6+5;
int n=read(),a[N],pos[N],l,r,ans;
signed main(){
	for(int i=1;i<=n;i++){
		a[i]=read();
		pos[a[i]]=i;
	}
	write(n*2+1),putchar(' ');
	l=n+1;
	for(int i=n;i>=n/2;i--){
		int len,tem,tl,tr;
		l=min(l,pos[i]);
		r=max(r,pos[i]);
		len=r-l+1;
		tem=(n-i)*2+1-len;
		if(tem>=0){
			tl=min(r+tem,n)-r;
			tr=l-max(l-tem,1);
			ans+=max(tl+tr-tem+1,0);
		}
		if(i==n)
			continue;
		tem=(n-i)*2-len;
		if(tem>=0){
			tl=min(r+tem,n)-r;
			tr=l-max(l-tem,1);
			ans+=max(tl+tr-tem+1,0);
		}
	}
	write(ans);
	return 0;
}
