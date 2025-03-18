#include<bits/stdc++.h>
using namespace std;
int a[100005];
int main()
{
    int n,k;
    scanf("%d%d",&n,&k);
    a[0]=1; a[1]=1;
    for(int i=2;i<=n;i++)
    {
        int sum=0;
        for(int j=i-1;j>=i-k;j--)
        {
            if(j<0)break;
            sum+=a[j];
            sum%=100003;
        }
        a[i]=sum;
        a[i]%=100003;
    }
    printf("%d",a[n]);
    return 0;
}