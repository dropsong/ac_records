#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#define int long long
#define R register
#define IL inline
#define Tf(a,b,c) for(R int (a)=(b);(a)>=(c);--(a))
using namespace std;
const int N=10000003;
int n,c[N],tot,k;
IL int read() {
    int x=0,f=1;char ch=getchar();
    while(ch>'9'||ch<'0'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x*=10;x+=(ch-'0');ch=getchar();}
    return x*f;
}
IL void write(int x) {
    if(x<0) putchar('-'),x=-x;
    if(x>9) write(x/10);
    putchar(x%10+'0');
}
signed main()
{
    n=read();k=read();
    for(R int i=1;i*i<=n;++i) if(n%i==0) {
        c[++tot]=i;
        k--;
        if(!k) {
            write(i);
            return 0;
        }
    }
    if(c[tot]*c[tot]==n) tot--;//льеп
    Tf(i,tot,1) {
        k--;
        if(!k) {
            write(n/c[i]);
            return 0;   
        }
    }
    write(-1);
    return 0;
}