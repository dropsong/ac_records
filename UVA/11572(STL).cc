#include<stdio.h>
#include<set>
#include<algorithm>
#define MAXN 1000006
using namespace std;

int a[MAXN];

int main()
{
    int t,n;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        for(int i=0;i<n;i++)scanf("%d",&a[i]);
        
        set<int> s;
        int l=0,r=0,ans=0;
        while(r<n)
        {
            while(r<n&&!s.count(a[r]))s.insert(a[r++]);
            ans=max(ans,r-l);
            s.erase(a[l++]);
        }
        printf("%d\n",ans);
    }
    
    return 0;
}