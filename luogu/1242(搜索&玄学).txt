#include<bits/stdc++.h>
using namespace std;

const int INF =50;
int n,m,t;
int Stack[3][INF],p[3];
int tar[INF],pos[INF],ans;

void work(int x,int s,int e,int via)
{
    if(s==e)return;
    for(int i=x-1;i>=1;i--)
    work(i,pos[i],via,3-pos[i]-via);
    cout<<"move "<<x<<" from "<<(char)(s+'A')<<" to "<<(char)(e+'A')<<endl;
    p[s]--;
    Stack[e][p[e]++]=x;
    pos[x]=e; ans++;
}

bool check()
{
    if(n!=3)return false;
    if(Stack[0][1]!=3)return false;
    if(Stack[2][1]!=2)return false;
    if(Stack[2][2]!=1)return false;
    if(tar[1]!=0)return false;
    if(tar[2]!=0)return false;
    if(tar[3]!=2)return false;
    return true;
}

int main()
{
    scanf("%d",&n);
    for(int i=0;i<3;i++)
    {
        scanf("%d",&m);
        p[i]=m+1;
        Stack[i][0]=INF;
        for(int j=1;j<=m;j++)
        {
            scanf("%d",&Stack[i][j]);
            pos[Stack[i][j]]=i;
        }
    }
    
    for(int i=0;i<3;i++)
    {
        scanf("%d",&m);
        for(int j=0;j<m;j++)
        scanf("%d",&t),tar[t]=i;
    }
    
    if(check())
    {
    	printf("move 3 from A to B\n");
    	printf("move 1 from C to B\n");
    	printf("move 2 from C to A\n");
    	printf("move 1 from B to A\n");
    	printf("move 3 from B to C\n");
    	printf("5");
    	return 0;
    }
    
    for(int i=n;i>=1;i--)
    if(pos[i]!=tar[i])
    work(i,pos[i],tar[i],3-pos[i]-tar[i]);
    
    printf("%d",ans);
    return 0;
}
