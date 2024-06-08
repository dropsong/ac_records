#include<bits/stdc++.h> 
using namespace std;

const int MAXN =5000+10;
int d[MAXN],n;
struct data{
    int l,w;
}info[MAXN];

bool cmp(data a,data b)
{
    if(a.l==b.l)return a.w>b.w;
    return a.l>b.l;
}

int LIS()
{
    int len=0;
    for(int i=1;i<=n;i++)
    {
        if(info[i].w>d[len])d[++len]=info[i].w;
        else
        {
            int l=1,r=len;
            while(l<r)
            {
                int mid=(l+r)>>1;
                if(d[mid]>=info[i].w)r=mid;
                else l=mid+1;
            }
            d[l]=info[i].w;
        }
    }
    return len;
}

int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    scanf("%d%d",&info[i].l,&info[i].w);
    sort(info+1,info+1+n,cmp);
    
    printf("%d",LIS());
    return 0;
}
