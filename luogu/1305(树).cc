#include<bits/stdc++.h>
#define MAXN 30
using namespace std;

int n;
struct node{
    char fa;
    char l,r;
}data[MAXN];

void output(char x)
{
    if(x=='*') return;
    for(int i=1;i<=n;i++)
    if(data[i].fa==x)
    {
        cout<<data[i].fa;
        output(data[i].l);
        output(data[i].r);
        return;
    }
}
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    cin>>data[i].fa>>data[i].l>>data[i].r;
    output(data[1].fa);
    return 0;
}