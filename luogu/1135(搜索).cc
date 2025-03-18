#include<bits/stdc++.h>
using namespace std;
int k[250];
int front,rear;
int vis[250];
int q[250][2];
int main()
{	
    int n,a,b;
    cin>>n>>a>>b;	
    for(int i=1;i<=n;i++)
    {
        cin>>k[i];
    }
    
    if(a==b)
    {
        cout<<0;
        return 0;
    }
    
    front=rear=1;
    q[1][0]=a;  q[1][1]=0;
    vis[a]=true;
    
    while(front<=rear)
    {
        int nx;
        int x=q[front][0];
        for(int j=1;j<=2;j++)
        {
            if(j==1)
            nx=x+k[q[front][0]];
            if(j==2)
            nx=x-k[q[front][0]];
            
            if(nx>=1&&nx<=n&&(!vis[nx]))
            {
                rear++;
                q[rear][0]=nx;
                q[rear][1]=q[front][1]+1;
                vis[nx]=true;
            }
            
            if(nx==b)
            {
                cout<<q[rear][1];
                return 0;
            }
        }
        front++;
    }
    cout<<-1;
    return 0;
}