#include<bits/stdc++.h>
using namespace std;

const int MAXM =1000000+10;
int n,m,tail;
int s[MAXM],prime[MAXM];
bool composite[MAXM];

void get_prime(int len)
{
    composite[0]=true;
    composite[1]=true;
    for(int i=2;i<=len;i++)
    {
        if(!composite[i])
        {
            prime[tail++]=i;
            s[i]=s[i-1]+1;
        }
        else s[i]=s[i-1];
        for(int j=0;j<tail&&i*prime[j]<=len;j++)
        {
            composite[i*prime[j]]=true;
            if(!(i%prime[j]))break;
        }
    }
}

int main()
{
    cin>>n>>m;
    get_prime(m);
    
    int l,r;
    while(n--)
    {
        scanf("%d%d",&l,&r);
        if(l<1||r>m||l>r)
            printf("Crossing the line\n");
        else
        {
            int ans=s[r]-s[l];
            if(!composite[l])ans++;
            printf("%d\n",ans);
        }
    }
    
    return 0;
}
