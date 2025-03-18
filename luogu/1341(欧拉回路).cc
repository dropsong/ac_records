#include<cstdio>
#define N 257
using namespace std;

int g[N][N],in[N],n,cnt,tail;
int uset[N];
char temp[N],order[N];

int find(int x)
{
    if(uset[x]!=x)uset[x]=find(uset[x]);
    return uset[x];
}

void dfs(int x)
{
    for(int i=0;i<N;i++)
    if(g[x][i])g[x][i]=g[i][x]=0,dfs(i);
    order[n--]=x;
}

int main()
{
    scanf("%d",&n);
    for(int i=0;i<N;i++)uset[i]=i; //makeset
    for(int i=1;i<=n;i++)
    {
        scanf("%s",temp);
        g[temp[0]][temp[1]]=1;
        g[temp[1]][temp[0]]=1;
        int fx=find(temp[0]),fy=find(temp[1]);
        uset[fx]=fy;
        in[temp[0]]++; in[temp[1]]++;
    }
    
    int sum=0;
    for(int i=0;i<N;i++)if(uset[i]==i&&in[i])sum++;
    if(sum!=1){
        printf("No Solution");
        return 0;
    }
    
    for(int i=0;i<N;i++)
    if(in[i]&1){
        cnt++;
        if(!tail)tail=i;
    }
    if(!tail)
    for(int i=0;i<N;i++)
    if(in[i]){
        tail=i;
        break;
    }
    
    if(cnt&&cnt!=2){
        printf("No Solution");
        return 0;
    }
    
    dfs(tail);
    puts(order);
    return 0;
}
