// luogu-judger-enable-o2
#include<iostream>
using namespace std;
int n,k,ans;
int a[10];

void dfs(int left,int pos)
{
    if(pos==k+1&&left==0){ans++;return;}
    if(pos==k+1&&left!=0)return;
    if(left<0)return;
    if(a[pos-1]*(k-pos+1)>left)return;
    for(int i=left;i>=1;i--)
    {
        if(a[pos-1]>i)continue;
        a[pos]=i; dfs(left-i,pos+1);
        a[pos]=0;
    }
}

int main()
{
    cin>>n>>k;
    dfs(n,1);
    cout<<ans;
    return 0;
}
