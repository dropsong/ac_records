//每一个不曾AC的日子都是一种遗憾。。。
#include<bits/stdc++.h>
#define HOME
using namespace std;

int f(int m,int n)
{
    if(n>m) return f(m,m);
    if(m==0) return 1;
    if(n==0) return 0;
    return f(m,n-1)+f(m-n,n);
}

int main()
{
    int t;
    cin>>t;
    int m,n;
    while(t--)
    {
        cin>>m>>n;
        cout<<f(m,n)<<endl;
    }
    
    return 0;
}