#include<bits/stdc++.h> 
using namespace std;
char arr[260];
int next[260],last[260];
int k,len;
int ans=0;
int main()
{
    scanf("%s %d",arr+1,&k);
    len=strlen(arr+1)+1;
    for(int i=0;i<=len;i++)
        last[i]=i-1,next[i]=i+1;
    int i=next[0];
    while(ans!=k && i!=len)
    {
        if(arr[i]>arr[next[i]])
        {
            next[last[i]]=next[i];
            last[next[i]]=last[i];
            i=next[0];
            ans++;
        }
        else
            i=next[i];
    }
    bool flag=true,flag1=false;
    i=next[0];
    while(i!=len)
    {
        if(flag && arr[i]=='0')
            i=next[i];
        else
        {
            printf("%c",arr[i]);
            flag1=true;
            flag=false;
            i=next[i];
        }
    }
    if(!flag1)
        printf("0");
    printf("\n");
    return 0;
} 