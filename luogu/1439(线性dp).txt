//每一个不曾AC的日子都是一种遗憾 
#include<bits/stdc++.h>
#define MAXN 100005 
using namespace std;

int n;
int a1[MAXN],a2[MAXN];
int a[MAXN],d[MAXN];
int mymap[MAXN];

inline int LIS()
{
    if(n==0)
    {
        printf("0\n");
        return 0;
    }
    
    d[1]=a[1];
    int len=1;
    for(int i=2;i<=n;i++)
    {
        if (a[i]>=d[len])d[++len]=a[i]; 
        else
        {
            int j=upper_bound(d+1,d+len+1,a[i])-d;
            d[j]=a[i]; 
        }
    }
    return len;
}

int main()
{
    //freopen(".in","r",stdin);
    //freopen(".out","w",stdout); 
    
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
    	scanf("%d",&a1[i]);
    	mymap[a1[i]]=i;
    }
    
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&a2[i]);
        a[i]=mymap[a2[i]];
    }
    
    printf("%d",LIS());
    return 0;
}