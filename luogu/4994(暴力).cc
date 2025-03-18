#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
#define int LL 

int f[5000000],m;
int ans[2000000],k;

inline int fib(int x)
{
    if(x==0)return 0;
    if(x==1)return 1;
    if(x==2)return 1;
    if(f[x])return f[x];
    int temp=fib(x-1)+fib(x-2);
    f[x]=temp%m;
    return f[x];
}

#undef int
int main()
{
#define int LL
    cin>>m;
    f[1]=1;f[2]=1;
    for(int i=1;i<=5000000;i++)fib(i);
    for(int i=1;i<=5000000;i++)
    if(f[i]==0&&f[i+1]==1){
        cout<<i;
        return 0;
    }
}
