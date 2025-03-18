#include<string.h>
#include<stdio.h>
#define MAXN 105
using namespace std;
char a[MAXN],b[MAXN];
bool check(int len1,int len2)
{
    if(len1<len2)return true;
    for(int i=0;i<len1;i++)
    {
        if(a[i]<b[i])return true;
    }
    return false;
}
int main()
{
    scanf("%s%s",a,b);
    int len1=strlen(a);
    int len2=strlen(b);
    if(check(len1,len2)){putchar('1');return 0;}
    else {printf("%s",a);return 0;}
}