//[JSOI2008]MST-counting
#include<bits/stdc++.h>
#define HA 31011
using namespace std;

int n,m,cnt,tot,ans=1,sum;
int uset[110];
struct edge{int x,y,w;}e[1010];
struct data{int l,r,num;}a[1010];

bool cmp(edge a,edge b){return a.w<b.w;}
int find(int x){return uset[x]==x?x:find(uset[x]);};

void dfs(int index,int now,int k)
{
    if(now==a[index].r+1)
    {
        if(k==a[index].num)sum++;
        return;
    }
    int p=find(e[now].x),q=find(e[now].y);
    if(p!=q)
    {
        uset[p]=q;
        dfs(index,now+1,k+1);
        uset[p]=p;uset[q]=q;
    }
    dfs(index,now+1,k);
}

int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)uset[i]=i; //makeset
    for(int i=1;i<=m;i++)
    scanf("%d%d%d",&e[i].x,&e[i].y,&e[i].w);
    sort(e+1,e+1+m,cmp);
    
    for(int i=1;i<=m;i++)           //MST
    {
        if(e[i].w!=e[i-1].w)
        {
            a[++cnt].l=i;
            a[cnt-1].r=i-1;
        }
        int p=find(e[i].x),q=find(e[i].y);
        if(p!=q){uset[p]=q;a[cnt].num++;tot++;}
    }
    a[cnt].r=m;
    if(tot!=n-1){putchar('0');return 0;} //special judge
    
    for(int i=1;i<=n;i++)uset[i]=i; //makeset
    for(int i=1;i<=cnt;i++)
    {
        sum=0;
        dfs(i,a[i].l,0);
        ans=(ans*sum)%HA;            //-1s
        for(int j=a[i].l;j<=a[i].r;j++)  //MST
        {
            int p=find(e[j].x),q=find(e[j].y);
            if(p!=q)uset[p]=q;
        }
    }
    
    printf("%d",ans);
    return 0;
}
