#include<iostream>
#include<string.h>
using namespace std;

const int MAXN=100010;
int sum[MAXN];

void build(int p)
{
    int v; cin>>v;
    if(v==-1)return;
    sum[p]+=v;
    build(p-1);build(p+1);
}

bool init()
{
    int v; cin>>v;
    if(v==-1)return false;
    memset(sum,0,sizeof(sum));
    int pos=MAXN>>1;
    sum[pos]=v;
    build(pos-1);build(pos+1);
    return true;
}

int main()
{
    //freopen(".in","r",stdin);
    //freopen(".out","w",stdout);
    int kase=0;
    while(init())
    {
        int p=0;
        while(!sum[p])p++;
        cout<<"Case "<<++kase<<":\n"<<sum[p++];
        while(sum[p])cout<<" "<<sum[p++];
        cout<<"\n\n";
    }
    
    return 0;
}
