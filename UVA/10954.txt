#include<cstdio>
#include<queue>

using namespace std;

int main()
{
    int n,x;
    while(scanf("%d",&n)==1&&n)
    {
        priority_queue<int,vector<int>,greater<int> >qwq;
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&x);
            qwq.push(x);
        }
        int sum=0;
        for(int i=1;i<=n-1;i++)
        {
            int a=qwq.top();qwq.pop();
            int b=qwq.top();qwq.pop();
            sum+=a+b;
            qwq.push(a+b);
        }
        printf("%d\n",sum);
    }
    
    return 0;
}
