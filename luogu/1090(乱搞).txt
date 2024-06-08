#include<bits/stdc++.h>
using namespace std;
int a[10001],n,s;
void input()
{
    scanf("%d",&n);
    for (int i=1;i<=n;i++) 
    {
        scanf("%d",&a[0]);
        int j=i-1;
        while (a[0]>a[j])
        {
            a[j+1]=a[j];
            j--; 
        } 
        a[j+1]=a[0];
    }
}
int main()
{
    input();
    for (int i=n-1;i>=1;i--)
    {
        a[i]+=a[i+1];
        s+=a[i];
        a[0]=a[i];
        int j=i-1;
        while (a[0]>a[j])
        {
            a[j+1]=a[j];
            j--; 
        } 
        a[j+1]=a[0];
    }
    printf("%d\n",s); 
    return 0;
}