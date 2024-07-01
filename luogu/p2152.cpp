#include <cstdio>
#include <ctype.h>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long LL;
typedef unsigned int uint;
#define rint register int
#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))

inline int rd() {
	int x=0,f=1;char ch=getchar();
	while(!isdigit(ch)) {if(ch=='-')f=-1;ch=getchar();}
	while(isdigit(ch))x=x*10+(ch^48),ch=getchar();
	return x*f;
}

const int N=10010;
const int base=10000;
const int limit=4;
int power_10[]={1,10,100,1000,1000,10000};

struct Bigint {
	int a[N],len;
	Bigint(){memset(a,0,sizeof(a)),len=0;}
	void clean(){while(len>1&&!a[len-1])len--;} //去前导0
    void init(LL x) {
		while(x)a[len++]=x%base,x/=base;
	}
	void read() {
		char s[N];
		scanf("%s",s);
		len=1;
		int n=strlen(s),t=0;
		for(rint i=n-1;~i;--i,++t) {
			a[len-1]+=(s[i]-'0')*power_10[t];
			if(t+1==limit)t=-1,++len;
		}
		if(!t)--len;
	}
	void print(char c=-1) {
		printf("%lld",a[len-1]);
		for(rint i=len-2;i>=0;--i)printf("%0*lld",limit,a[i]);
		if(~c)putchar(c);
	}

    Bigint(int num){*this=num;}
    Bigint(char* num){*this=num;}
    Bigint operator = (const char* num){
        len=strlen(num);
        for(int i=0;i<len;i++)a[i]=num[len-1-i]-'0';
        clean();
        return *this;
    }
    Bigint operator = (int num){
        char s[N];
        sprintf(s,"%d",num);
        *this=s;
        return *this;
    }

    bool operator < (const Bigint& b)const{
        if(len!=b.len)return len<b.len;
        for(rint i=len-1;~i;i--)
            if(a[i]!=b.a[i])return a[i]<b.a[i];
        return false;
    }
    bool operator > (const Bigint& b)const{return b<*this;}
    bool operator <= (const Bigint& b)const{return !(b<*this);}
    bool operator >= (const Bigint& b)const{return !(*this<b);}
    bool operator != (const Bigint& b)const{return b<*this||*this<b;}
    bool operator == (const Bigint& b)const{return !(b<*this)&&!(b>*this);}
};
Bigint operator + (const Bigint &a,const Bigint &b) {
	Bigint c;int mx=MAX(a.len,b.len);c.len=mx;
	for(rint i=0;i<mx;++i)c.a[i]=a.a[i]+b.a[i];
	for(rint i=0;i<mx;++i)if(c.a[i]>=base)++c.a[i+1],c.a[i]-=base;
	if(c.a[c.len])++c.len;
	return c;
}
Bigint operator - (const Bigint &a,const Bigint &b) {
	Bigint c;int mx=a.len;c.len=mx;
	for(rint i=0;i<mx;++i)c.a[i]=a.a[i]-b.a[i];
	for(rint i=0;i<mx;++i)if(c.a[i]<0)--c.a[i+1],c.a[i]+=base;
	while(c.len&&!c.a[c.len-1])--c.len;
	return c;
}
Bigint operator * (const Bigint &a,const Bigint &b) {
	Bigint c;int mx=a.len+b.len-1;c.len=mx;
	for(rint i=0,mxa=a.len;i<mxa;++i)
		for(rint j=0,mxb=b.len;j<mxb;++j) {
			c.a[i+j]+=a.a[i]*b.a[j];
			if(c.a[i+j]>=base)c.a[i+j+1]+=c.a[i+j]/base,c.a[i+j]%=base;
		}
	if(c.a[c.len])++c.len;
	return c; 
}
Bigint operator / (const Bigint &a,const int &b) {
	Bigint c;int mx=a.len;
	LL now=0;
	for(rint i=mx-1,s=0;~i;--i) {
		now=now*base+a.a[i];
		if(now/b)s=1;
		if(!s)continue;
		c.a[c.len++]=now/b;
		now%=b;
	}
	reverse(c.a,c.a+c.len);
	return c;
}

Bigint biggcd(Bigint x,Bigint y){
    int xcnt2=0, ycnt2=0;
    while(!(x.a[0]&1)){xcnt2++; x=x/2;}
    while(!(y.a[0]&1)){ycnt2++; y=y/2;}
    int z=MIN(xcnt2,ycnt2);
    while(x!=y){
        if(x<y){swap(x,y);}
        x=x-y;
        while(!(x.a[0]&1)){x=x/2;}
    }
    Bigint temp = 2;
    while(z--){x=x*temp;}
    return x;
}

int main(){
    Bigint a,b;
    a.read(); b.read();
    biggcd(a,b).print();
    return 0;
}