#include<stdio.h>
#include<iostream>
#include<string.h>
#include<string>
#include<algorithm>
#define HOME
#define MAXN 30005
using namespace std;

int a[MAXN];
int sum;
bool b[MAXN];

inline void TEST(string ch,int i)
{
    cout<<"test: "<<ch<<"="<<i<<endl;
    system("pause");
}

int main()
{
#ifdef NOIP
    freopen(".in","r",stdin);
    freopen(".out","w",stdout);
#endif

    memset(b,true,sizeof(b));
    int w,n;
    scanf("%d%d",&w,&n);
    
    for(int i=1;i<=n;i++)
     scanf("%d",&a[i]);
    
    sort(a+1,a+1+n);
    
    /*
    //====test=====
    for(int i=1;i<=n;i++)
    printf("%d ",a[i]);
    return 0;
    //====test=====
    */
    
    bool flag=false;
    for(int i=n;i>1;i--)
    {
    	//TEST("i",i);
    	//TEST("sum",sum);
        if(!b[i])continue;
        flag=false;
        for(int j=i-1;j>=1;j--)
        {
            if(a[i]+a[j]<=w && b[j]){
                sum++;
                b[i]=b[j]=false;
                flag=true;
                break;
            }
        }
        if(!flag){
            sum++;
            b[i]=false;
        }
    }	
    if(b[1]) sum++;
    printf("%d",sum);
    
    return 0;
}