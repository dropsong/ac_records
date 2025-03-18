#include<bits/stdc++.h>
using namespace std;

const int MAXN=50000+10;
int l,n,m,ans;
int d[MAXN];

bool check(int dis)
{
    int temp=0,sum=0;
    for(int i=1;i<=n;i++)
    if(d[i]-temp>=dis) temp=d[i];
    else sum++;
    if(l-temp<dis) sum++;
    
    if(sum>m)return false;
    else return true;
}

void work()
{
    int left=1,right=l;
    while(left<right)
    {
        int mid=(left+right)>>1;
        if(check(mid))
        {
            ans=mid;
            left=mid+1;
        }
        else right=mid;
    }
}

int main()
{
    cin>>l>>n>>m;
    for(int i=1;i<=n;i++)
    scanf("%d",&d[i]);
    work();
    if(n==0)ans=l;
    cout<<ans; 
    return 0;
 } 
