#include<bits/stdc++.h> 
using namespace std;
const int maxn=1000010;
bool a[maxn];
int t;
int main()
{
    int n,sum1=0,sum2=0;
    int x,y;
    int maxx=0,minx=maxn;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>x>>y;
        minx=min(x,minx);
        maxx=max(y,maxx);
        for(int i=x;i<y;i++)a[i]=1;    
    }
    int start=minx;
    int end=maxx;
    for(int i=start;i<=end;i++)
    {    
        if(a[i]==1)t++;
        else 
        {
            sum1=max(sum1,t);        
            t=0;
        }
    }
    for(int i=start;i<=end;i++)
    {    
        if(a[i]==0)t++;
        else 
        {
            sum2=max(sum2,t);
            t=0;        
        }
    }
    cout<<sum1<<" "<<sum2<<endl; 
    return 0;
}