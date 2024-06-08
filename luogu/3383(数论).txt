#include<bits/stdc++.h>
#define MAXN 10000010
using namespace std;

int n,m,a;
bool s[MAXN];
int p[MAXN],pz;

inline void getprime()
{
    s[0]=0;s[1]=0;
    for(int i=2;i<=n;i++)
    {
        if(s[i])p[pz++]=i;
        for(int j=0;j<pz&&i*p[j]<=n;j++)
        {
            s[i*p[j]]=0;
            if(!(i%p[j]))break;
        }
    }
}
int main()
{
    cin>>n>>m;
    memset(s,true,sizeof(s));
    getprime();
    
    for(int i=1;i<=m;i++)
    {
        cin>>a;
        if(s[a])cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }
    
    return 0;
}