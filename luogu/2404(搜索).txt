//其实这题可以打表233...
#include<cstdio>
using namespace std;
int ans[10];
int n;
void output(int len)
{
    for(int i=0;i<len-1;i++)
    printf("%d+",ans[i]);
    printf("%d\n",ans[len-1]);
}
void dfs(int left,int len)
{
    if(left==0)
    {
        output(len);
        return;
    }
    if(left<0)return;
    else
    {
        for(int j=1;j<n;j++)
        {
            if(j<ans[len-1])continue;
            ans[len]=j;
            left-=j;
            dfs(left,++len);
            --len;
            ans[len]=0;
            left+=j;
        }
    }
}
int main()
{
    scanf("%d",&n);
    dfs(n,0);
    return 0;
} 