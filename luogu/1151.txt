#include<bits/stdc++.h>
using namespace std;
bool ok;
int k,i,sub1,sub2,sub3;
void qushu(int x)
{
    sub1=x/100;
    sub2=(x/10)%1000;
    sub3=x%1000;
}
bool judge()
{
    if(sub1%k==0&&sub2%k==0&&sub3%k==0)
    return true;
    return false;
}
int main()
{
    scanf("%d",&k);
    for(i=10000;i<=30000;i++)
    {
        qushu(i);
        if(judge())
        {
            ok=true;
            printf("%d\n",i);
        }
    }
    if(!ok)printf("No\n");
    return 0;
}