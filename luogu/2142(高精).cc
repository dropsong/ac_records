#include<iostream> 
#include<string> 
#include<cstring>
#define MAXN 10010 
using namespace std; 

int a[MAXN],b[MAXN],c[MAXN]; 

bool check(int a[],int b[]){ 
    if(a[0]>b[0])return false; 
    if(a[0]<b[0])return true; 
    for(int i=a[0];i>=1;i--){ 
        if(a[i]<b[i]) return true; 
        if(a[i]>b[i]) return false; 
    } 
    return false;
}

void read(int a[]){ 
    string s; 
    cin>>s; 
    a[0]=s.size(); 
    for(int i=0;i<a[0];i++){ 
        a[a[0]-i]=s[i]-'0'; 
    } 
}

void write(int a[]){ 
    for(int i=a[0];i>=1;i--){ 
        cout<<a[i]; 
    } 
    cout<<endl; 
}

void add(int a[],int b[]){
    memset(c,0,sizeof(c)); 
    c[0]=a[0]>b[0]?a[0]:b[0]; 
    int g=0;
    for(int i=1;i<=c[0];i++){ 
        c[i]=a[i]+b[i]+g; 
        g=c[i]/10; 
        c[i]%=10; 
    } 
    if(g!=0)c[++c[0]]=g; 
}

void subtract(int a[],int b[]){
    if(check(a,b)){ 
        int *p;
        p=a; a=b; b=p;
        cout<<"-";
    } 
    memset(c,0,sizeof(c)); 
    for(int i=1;i<=a[0];i++){ 
        if(a[i]<b[i]){ 
            a[i]+=10; 
            a[i+1]--; 
        } 
        c[i]=a[i]-b[i]; 
    }  
    int len=a[0]; 
    while(c[len]==0&&len!=1)len--; 
    c[0]=len;
}

int main()
{
    read(a); 
    read(b); 
    subtract(a,b); 
    write(c);
    return 0; 
}
