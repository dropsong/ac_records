#include<bits/stdc++.h>
using namespace std;
const int maxn=48;
double a[maxn],b[maxn];
int main()
{
    int n;
    scanf("%d",&n);
    double k1=(1+sqrt(5))/2,
           k2=(1-sqrt(5))/2;
    double temp1=1,temp2=1,sum=0;
    for(int i=0;i<n;i++)
    {
        a[i]=temp1;
        temp1*=k1;
    }
    for(int i=0;i<n;i++)
    {
        b[i]=temp2;
        temp2*=k2;
    }
    for(int i=n-1,j=0;i>=0,j<=n-1;i--,j++)
    {
        sum+=a[i]*b[j];
    }
    printf("%.2lf",sum);
    return 0;
}