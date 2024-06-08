#include<bits/stdc++.h>
using namespace std;
int a[10010];
int main()
{
    int n,temp=0,ans=-999;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        if(a[i]==a[i-1]+1&&a[i-1])temp++;
        else{
            ans=max(ans,temp);
            temp=0;
        }
    }
    cout<<ans+1;
    return 0;
}