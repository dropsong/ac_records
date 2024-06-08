#include<cstdio>
#include<algorithm>
using namespace std;
const int MAXN=105;
int r,c;
struct node
{
    int x,y;
    int sum;
    int l;
}a[MAXN*MAXN];
bool cmp(node j,node c)
{ 
    return j.sum < c.sum ;
}
inline void input()
{
    scanf("%d%d",&r,&c);
    for(int i=1;i<=r;i++)
    for(int j=1;j<=c;j++)
    {
        a[c*(i-1)+j].l =1;
        a[c*(i-1)+j].x =i;
        a[c*(i-1)+j].y =j;
        scanf("%d",&a[c*(i-1)+j].sum);
    }
}
inline bool judge(int zxx,int k)
{
    if(abs(a[zxx].x-a[k].x)==1&&abs(a[zxx].y-a[k].y)==0)return true;
    if(abs(a[zxx].x-a[k].x)==0&&abs(a[zxx].y-a[k].y)==1)return true;
    return false;
}
int main()
{
    input();
    sort(a+1,a+1+r*c,cmp);
    int max_play_len=0;
    for(int k=1;k<=r*c;k++)
    {
        int max_len=0;
        for(int zxx=k-1;zxx>=1;zxx--)
        {
            if(zxx==0)break;
            if(judge(zxx,k)&&a[zxx].l>max_len&&a[zxx].sum<a[k].sum)max_len=a[zxx].l;
        }
        a[k].l+=max_len;
        if(a[k].l>max_play_len)max_play_len=a[k].l;
    }
    printf("%d",max_play_len);
    return 0;
}