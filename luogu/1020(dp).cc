// luogu-judger-enable-o2
//每一个不曾AC的日子都是一种遗憾
#include<stdio.h>
#include<vector>
#include<algorithm>
#define MAXN 100005
using namespace std;

int dis=1;
int a[MAXN],d[MAXN];
vector<int> hei;

inline int LIS()
{
    d[1]=a[1];
    int len=1;
    for(int i=2;i<dis;i++)
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
        
    int sum=0;
    
    while(scanf("%d",&a[dis])==1)
    {
        vector<int>::iterator result;
        sort(hei.begin(),hei.end());
        result=lower_bound(hei.begin(),hei.end(),a[dis]);
        
        if(result-hei.end()>=0)
        {
            sum++;
            hei.push_back(a[dis]);
        }
        else *result=a[dis];
        
        dis++;
    }
    
    for(int k=1;k<dis;k++)
    a[k]=-a[k];
    
    printf("%d\n",LIS());
    printf("%d",sum);
    
    return 0;
}