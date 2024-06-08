#include<stdio.h>
#include<iostream>
#include<cstring>
#define HOME
using namespace std;

int n,pre=-1,ans=-1,sumup;
struct node
{
    char c[25];
    int score_exam,
        score_class;
    char leader;
    char province;
    int sum_paper;
}a[105];

 inline void input()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        int total=0;
        scanf("%s",a[i].c);
        scanf("%d%d",&a[i].score_exam,&a[i].score_class);
        cin>>a[i].leader;
        cin>>a[i].province;
        scanf("%d",&a[i].sum_paper);
        
        if(a[i].score_exam>80&&a[i].sum_paper>=1)total+=8000;
        if(a[i].score_exam>85&&a[i].score_class>80)total+=4000;
        if(a[i].score_exam>90)total+=2000;
        if(a[i].score_exam>85&&a[i].province=='Y')total+=1000;
        if(a[i].score_class>80&&a[i].leader=='Y')total+=850;
        
        sumup+=total;
        
        if(total>pre){
            pre=total;
            ans=i;
        }
    }
    
}

int main()
{
#ifdef NOIP
    freopen(".in","r",stdin);
    freopen(".out","w",stdout);
#endif
    input();
    
    printf("%s\n",a[ans].c);
    printf("%d\n",pre);
    printf("%d\n",sumup);
    
    return 0;
}