#include<bits/stdc++.h>
using namespace std;
const int MAXN=40005;
int total;
int a[MAXN],r[MAXN];
void msort(int s,int t)
{
    if(s==t)return;
    int mid=(s+t)/2;
    msort(s,mid);
    msort(mid+1,t);
    int i=s,j=mid+1,k=s;
    while(i<=mid&&j<=t)
    {
        if(a[i]<=a[j])
        {
            r[k]=a[i];
            k++; i++;
        }
        else 
        {
            total+=mid-i+1;
            r[k]=a[j];
            k++; j++;
        }
    }
    while(i<=mid)
    {
        r[k]=a[i];
        k++; i++;
    }
    while(j<=t)
    {
        r[k]=a[j];
        k++; j++;
    }
    for(int o=s;o<=t;o++) a[o]=r[o];
}

int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
    }
    msort(1,n);
    printf("%d",total);
    return 0;
}