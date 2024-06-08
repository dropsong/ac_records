#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,m,temp,sum=0,ans=0;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&temp);
        sum+=temp;
        if(sum>m)
        {
            sum=temp;
            ans++;
        }
    }
    printf("%d",ans+1);
    return 0;
}