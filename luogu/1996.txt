#include<bits/stdc++.h>
using namespace std;
const int MAXN=105;
bool a[MAXN];
int b[MAXN];
int main()
{
    int n,m,ans=0,pos=0;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
    {
        while(ans<m)
        {
            pos++;
            if(pos==n+1)pos=1;
            if(!a[pos])ans++;
        }
        a[pos]=true; ans=0;
        b[i]=pos;
    }
    for(int i=1;i<=n;i++)
    {
        printf("%d ",b[i]);
    }
    return 0;
}