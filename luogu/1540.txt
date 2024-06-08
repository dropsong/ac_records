#include<iostream>
using namespace std;
int queue[10000],head=1,tail=1,cnt=0;
int main()
{
    int m,n,a;
    cin>>m>>n;
    for(int i=1;i<=n;++i)
    {
        bool flag=0;
        
        cin>>a;
        
        for(int j=head;j<tail;++j)
        {
            if(queue[j]==a)
            {
                flag=1;
                break;
            }
        }
        
        
        if(!flag)
        {
            ++cnt;
            queue[tail]=a;
            tail++;
        }
        if(tail-head>=m+1)head++;
    }
    cout<<cnt;
    return 0;
}