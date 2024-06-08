#include<bits/stdc++.h>
using namespace std;
int n,s,a,b,height,len,total;
const int MAXN=5005;
struct apple
{
    int HEIGHT,
        STRENGTH;
}kkk[MAXN];
void input()
{
    scanf("%d%d",&n,&s);
    scanf("%d%d",&a,&b);
    height=a+b;
    int i,k;
    for(i=0,k=0;k<n;k++)
    {
        int temp1,temp2;
        scanf("%d",&temp1);
        scanf("%d",&temp2);
        if(temp1>height) continue;
        kkk[i].HEIGHT=temp1;
        kkk[i].STRENGTH=temp2;
        i++;
    }
    len=i;
}
bool cmp(apple x,apple y)
{
    return x.STRENGTH<y.STRENGTH;
}
int main()
{
    input();
    sort(kkk,kkk+len,cmp);
    for(int j=0;j<len;j++)
    {
        s-=kkk[j].STRENGTH;
        if(s>=0)total++;
    }
    printf("%d",total);
    return 0;
}