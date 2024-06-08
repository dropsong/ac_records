#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t,pre=0,temp;
    cin>>t;
    while(t--)
    {
        int n; cin>>n; pre=0;
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&temp);
            pre=temp^pre;
        }
        if(pre)printf("Yes\n");
        else printf("No\n");
    }
    return 0;
}
