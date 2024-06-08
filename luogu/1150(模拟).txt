#include<bits/stdc++.h>
using namespace std;
int sum,lest;
int main()
{
    int n,k;
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++)
    {
        sum++;lest++;
        if(lest%k==0)
        {
            sum++;
            lest=1;
        }
    }
    printf("%d",sum);
    return 0;
}